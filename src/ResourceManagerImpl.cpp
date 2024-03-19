#include <NTTEngine/ResourceManager/ResourceManagerImpl.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <NTTEngine/Common.hpp>
#include <NTTEngine/ResourceManager/ResourceDef.hpp>
#include <NTTEngine/GraphicManager/GraphicResource.hpp>

#include <nlohmann/json.hpp>

namespace ntt
{
    ResourceManagerImpl *ResourceManagerImpl::m_Instance;

    static Ref<ResourceObject> ExtractObjectFromJsonObject(nlohmann::json obj);

    ResourceManagerImpl::ResourceManagerImpl()
        : m_CurrentScope(RESOURCE_SCOPE_GLOBAL)
    {
    }

    ResourceManagerImpl::~ResourceManagerImpl()
    {
        // ClearResources();
    }

    void ResourceManagerImpl::LoadResources(const std::string &resourcePath)
    {
        std::string content = ReadJsonFileContent(resourcePath);

        // Parse the string into JSON
        nlohmann::json jsonObject;

        try
        {
            jsonObject = nlohmann::json::parse(content);
        }
        catch (nlohmann::json::parse_error &e)
        {
            LOG_ERROR("Failed to parse JSON: " + std::string(e.what()));
            return;
        }

        // Load the resources' metadata
        if (jsonObject.is_array())
        {
            for (const auto &element : jsonObject)
            {
                Ref<ResourceObject> resource = ExtractObjectFromJsonObject(element);

                if (resource == nullptr)
                {
                    LOG_WARN("Failed to extract resource from JSON object.");
                    continue;
                }
                else
                {
                    m_Resources[element["scope"]].push_back(resource);
                }
            }

            LoadResouceByScope(0);
        }
        else
        {
            LOG_ERROR("JSON file must be the array of resources.");
        }
    }

    std::string ResourceManagerImpl::ReadJsonFileContent(const std::string &path)
    {
        std::ifstream file(path);

        if (!file.is_open())
        {
            LOG_ERROR("Failed to open resource file: " + path);
            return "";
        }

        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        file.close();

        return content;
    }

    Ref<ResourceObject> ExtractObjectFromJsonObject(nlohmann::json obj)
    {
        // Check the "id" field exists and is an integer
        if (!obj.contains("id") || !obj["id"].is_number_integer())
        {
            LOG_WARN("Resource must have an integer id.");
            return nullptr;
        }

        // Check the "scope" field exists and is an integer
        if (!obj.contains("scope") || !obj["scope"].is_number_integer())
        {
            LOG_WARN("Resource must have an integer scope.");
            return nullptr;
        }

        // Check the "type" field exists and is an integer
        if (!obj.contains("type") || !obj["type"].is_number_integer())
        {
            LOG_WARN("Resource must have an integer type.");
            return nullptr;
        }

        // Check the "filePath" field exists and is a string
        if (!obj.contains("filePath") || !obj["filePath"].is_string())
        {
            LOG_WARN("Resource must have a string \"filePath\".");
            return nullptr;
        }

        // TODO: Check the "id" field is unique
        Ref<ResourceObject> resource;

        switch (static_cast<ResourceType>(obj["type"]))
        {
        case ResourceType::RT_GRAPHICS:
            resource = MakeRef<GraphicResource>(obj["id"],
                                                obj["scope"],
                                                obj["filePath"]);
            break;

        default:
            resource = MakeRef<ResourceObject>(
                obj["id"], obj["scope"],
                obj["filePath"],
                static_cast<ResourceType>(obj["type"]));
        }

        return resource;
    }

    void ResourceManagerImpl::LoadResouceByScope(uint8_t scope)
    {
        for (const auto &resource : m_Resources[scope])
        {
            resource->Load();
        }
    }

    void ResourceManagerImpl::UnloadResourcesByScope(uint8_t scope)
    {
        for (const auto &resource : m_Resources[scope])
        {
            resource->Unload();
        }
    }

    void ResourceManagerImpl::ClearResources()
    {
        // Unload all resources with all keys from the dictionary
        for (const auto &pair : m_Resources)
        {
            UnloadResourcesByScope(pair.first);
        }
    }

    void ResourceManagerImpl::SetScope(uint8_t scope)
    {
        if (m_CurrentScope != RESOURCE_SCOPE_GLOBAL)
        {
            UnloadResourcesByScope(m_CurrentScope);
        }

        if (scope != RESOURCE_SCOPE_GLOBAL)
        {
            LoadResouceByScope(scope);
        }

        m_CurrentScope = scope;
    }

    Ref<ResourceObject> ResourceManagerImpl::GetResourceById(uint8_t rid)
    {
        for (const auto &pair : m_Resources)
        {
            for (const auto &resource : pair.second)
            {
                if (resource->GetRID() == rid)
                {
                    return resource;
                }
            }
        }

        return nullptr;
    }

    void ResourceManagerImpl::InitResourceManagerIns()
    {
        if (m_Instance == nullptr)
        {
            m_Instance = new ResourceManagerImpl();
        }
    }

    void ResourceManagerImpl::ReleaseResourceManagerIns()
    {
        if (m_Instance != nullptr)
        {
            delete m_Instance;
            m_Instance = nullptr;
        }
    }

    void InitResourceManager()
    {
        ResourceManagerImpl::InitResourceManagerIns();
    }

    ResourceManager *GetResourceManager()
    {
        return ResourceManagerImpl::GetResourceManagerInstance();
    }

    void ReleaseResourceManager()
    {
        ResourceManagerImpl::ReleaseResourceManagerIns();
    }
}
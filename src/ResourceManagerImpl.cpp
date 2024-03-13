#include <NTTEngine/ResourceManager/ResourceManagerImpl.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <NTTEngine/Common.hpp>

#include <nlohmann/json.hpp>

namespace ntt
{
    ResourceManagerImpl ResourceManagerImpl::m_Instance;

    ResourceManagerImpl::ResourceManagerImpl()
    {
    }

    ResourceManagerImpl::~ResourceManagerImpl()
    {
    }

    void ResourceManagerImpl::LoadResources(const std::string &resourcePath)
    {
        // Read content from the resource file
        std::ifstream file(resourcePath);

        if (!file.is_open())
        {
            LOG_ERROR("Failed to open resource file: " + resourcePath);
            return;
        }

        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        file.close();

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
                // Check the "id" field exists and is an integer
                if (!element.contains("id") || !element["id"].is_number_integer())
                {
                    LOG_WARN("Resource must have an integer id.");
                    continue;
                }

                // Check the "scope" field exists and is an integer
                if (!element.contains("scope") || !element["scope"].is_number_integer())
                {
                    LOG_WARN("Resource must have an integer scope.");
                    continue;
                }

                // Check the "type" field exists and is an integer
                if (!element.contains("type") || !element["type"].is_number_integer())
                {
                    LOG_WARN("Resource must have an integer type.");
                    continue;
                }

                // Check the "filePath" field exists and is a string
                if (!element.contains("filePath") || !element["filePath"].is_string())
                {
                    LOG_WARN("Resource must have a string \"filePath\".");
                    continue;
                }

                // TODO: Check the "id" field is unique

                Ref<ResourceObject> resource = MakeRef<ResourceObject>(
                    element["id"], element["scope"],
                    element["filePath"],
                    static_cast<ResourceType>(element["type"]));

                m_Resources[element["scope"]].push_back(resource);
            }

            // Load all global resources
            for (const auto &resource : m_Resources[0])
            {
                resource->Load();
            }
        }
        else
        {
            LOG_ERROR("JSON file must be the array of resources.");
        }
    }

    void ResourceManagerImpl::ClearResources()
    {
        LOG_INFO("Clear resources: ");
    }

    void ResourceManagerImpl::SetScope(uint8_t scope)
    {
        LOG_INFO("Set scope: " + std::to_string(scope));
    }

    ResourceObject *ResourceManagerImpl::GetResourceById(uint8_t rid)
    {
        return nullptr;
    }

    ResourceManager *GetResourceManager()
    {
        return ResourceManagerImpl::GetResourceManagerInstance();
    }
}
#include <NTTEngine/ResourceManager/ResourceObject.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>

namespace ntt
{
    ResourceObject::ResourceObject(uint8_t rid, uint8_t scope,
                                   const std::string &filePath, ResourceType type)
        : m_RID(rid), m_Scope(scope),
          m_FilePath(filePath),
          m_Type(type), m_Loaded(false)
    {
    }

    ResourceObject::~ResourceObject()
    {
    }

    void ResourceObject::Load()
    {
        if (!m_Loaded)
        {
            m_Loaded = LoadImpl();
        }
    }

    void ResourceObject::Unload()
    {
        if (m_Loaded)
        {
            UnloadImpl();
            m_Loaded = false;
        }
    }

    bool ResourceObject::LoadImpl()
    {
        LOG_INFO("Load resource: " + std::to_string(m_RID));
        return true;
    }

    void ResourceObject::UnloadImpl()
    {
        LOG_INFO("Unload resource: " + std::to_string(m_RID));
    }
} // namespace ntt
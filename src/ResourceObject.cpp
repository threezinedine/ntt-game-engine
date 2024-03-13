#include <NTTEngine/ResourceManager/ResourceObject.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>

namespace ntt
{
    ResourceObject::ResourceObject(uint8_t rid, uint8_t scope,
                                   const std::string &filePath, ResourceType type)
        : m_RID(rid), m_Scope(scope), m_FilePath(filePath), m_Type(type)
    {
    }

    ResourceObject::~ResourceObject()
    {
    }

    void ResourceObject::Load()
    {
        LOG_INFO("Loading resource: " + m_FilePath);
        LoadImpl();
    }

    void ResourceObject::Unload()
    {
        LOG_INFO("Unloading resource: " + m_FilePath);
        UnloadImpl();
    }

    void ResourceObject::LoadImpl()
    {
    }

    void ResourceObject::UnloadImpl()
    {
    }
} // namespace ntt
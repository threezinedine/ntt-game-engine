#pragma once

#include <NTTEngine/Common.hpp>
#include <NTTEngine/ResourceManager/ResourceManager.hpp>

namespace ntt
{
    class ResourceManagerImpl : public ResourceManager
    {
    public:
        ResourceManagerImpl();
        ~ResourceManagerImpl() override;

        void LoadResources(const std::string &path) override;
        void ClearResources() override;
        void SetScope(uint8_t scope) override;
        ResourceObject *GetResourceById(uint8_t rid) override;

        static inline ResourceManager *GetResourceManagerInstance() { return &m_Instance; }

    private:
        /**
         * @brief Singleton instance of ResourceManagerImpl
         */
        static ResourceManagerImpl m_Instance;

        /**
         * @brief Dictionary of resources
         *
         * Key: Scope of the resource
         * Value: ResourceObject
         */
        Dictionary<uint8_t, List<Ref<ResourceObject>>> m_Resources;
    };
} // namespace ntt

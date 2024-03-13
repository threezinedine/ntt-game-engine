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
        Ref<ResourceObject> GetResourceById(uint8_t rid) override;

        static inline ResourceManager *GetResourceManagerInstance() { return m_Instance; }
        static void InitResourceManagerIns();
        static void ReleaseResourceManagerIns();

    protected:
        /**
         * @brief Read the content of a JSON file
         * @param path Path to the JSON file
         * @return Content of the JSON file
         */
        std::string ReadJsonFileContent(const std::string &path);

        /**
         * @brief Load all resources with the given scope
         */
        void LoadResouceByScope(uint8_t scope);

        /**
         * @brief Unload all resources with the given scope
         */
        void UnloadResourcesByScope(uint8_t scope);

    private:
        /**
         * @brief Singleton instance of ResourceManagerImpl
         */
        static ResourceManagerImpl *m_Instance;

        /**
         * @brief Dictionary of resources
         *
         * Key: Scope of the resource
         * Value: ResourceObject
         */
        Dictionary<uint8_t, List<Ref<ResourceObject>>> m_Resources;

        uint8_t m_CurrentScope;
    };
} // namespace ntt

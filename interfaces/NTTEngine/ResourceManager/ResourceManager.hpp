#pragma once

#include <NTTEngine/Common.hpp>
#include <NTTEngine/EngineObject.hpp>

#include "ResourceObject.hpp"

namespace ntt
{
    class ResourceManager : public EngineObject
    {
    public:
        virtual ~ResourceManager() = default;

        /**
         * @brief Load a resource from a json file.
         *
         * All the resources' metadata which are stored in a json file will
         *      be loaded into the memory. And the resources' data with GLOBAL scope
         *      will be loaded into the memory. Other resources' data will be loaded
         *      later when the scene is run.
         *
         *  @param path The path of the json file.
         */
        virtual void LoadResources(const std::string &path) = 0;

        /**
         * @brief Unload a resource from memory.
         *
         * All the resources' metadata which are stored in a json file will
         *      discarded from the memory.
         */
        virtual void ClearResources() = 0;

        /**
         * @brief Load all the resources with the given scope.
         *
         * The resources' data with the given scope will be loaded into the memory.
         *      and the resources' data of the previous scope will be discarded.
         *      The resources' data with the GLOBAL scope is still in the memory.
         */
        virtual void SetScope(uint8_t scope) = 0;

        /**
         * @brief Get the resource object by the resource ID.
         *
         * @param rid The resource ID.
         * @return The resource object pointer (do not to be freed later).
         */
        virtual Ref<ResourceObject> GetResourceById(uint8_t rid) = 0;
    };

    void InitResourceManager();
    ResourceManager *GetResourceManager();
    void ReleaseResourceManager();
} // namespace ntt

#define INIT_RESOURCE_MANAGER() ntt::InitResourceManager()
#define LOAD_RESOURCES(path) ntt::GetResourceManager()->LoadResources(path)
#define UNLOAD_RESOURCES() ntt::GetResourceManager()->ClearResources()
#define CLEAR_RESOURCES() ntt::GetResourceManager()->ClearResources()
#define SET_SCOPE(scope) ntt::GetResourceManager()->SetScope(scope)
#define GET_RESOURCE_BY_ID(rid) ntt::GetResourceManager()->GetResourceById(rid)
#define RELEASE_RESOURCE_MANAGER() ntt::ReleaseResourceManager()
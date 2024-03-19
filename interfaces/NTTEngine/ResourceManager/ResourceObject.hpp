#pragma once

#include <NTTEngine/Common.hpp>
#include <NTTEngine/EngineObject.hpp>

#include "ResourceType.hpp"

namespace ntt
{
    /**
     * @brief The base class for all resources
     */
    class ResourceObject : public EngineObject
    {
    public:
        /**
         * @brief Construct a new Resource Object object
         *
         * @param rid The resource ID
         * @param scope The resource scope
         * @param filePath The resource file path
         * @param type The resource type
         */
        ResourceObject(uint8_t rid, uint8_t scope,
                       const std::string &filePath, ResourceType type);

        virtual ~ResourceObject();

        /**
         * @brief Get the resource ID
         *
         * @return The resource ID
         */
        inline uint8_t GetRID() const { return m_RID; }
        /**
         * @brief Get the resource scope
         *
         * @return The resource scope
         *      0 - Global
         *      1 -> n - Scene specific (n is the number of scenes in the game)
         */
        inline uint8_t GetScope() const { return m_Scope; }

        /**
         * @brief Get the resource file path
         *
         * @return The resource file path
         */
        inline const std::string &GetFilePath() const { return m_FilePath; }

        /**
         * @brief Get the resource type
         *
         * @return The resource type
         */
        inline ResourceType GetType() const { return m_Type; }

        /**
         * @brief The comprehensive resource loading process
         */
        void Load();

        /**
         * @brief The comprehensive resource unloading process
         */
        void Unload();

        /**
         * @brief Check whether the resource is loaded
         *
         * @return true if the resource is loaded
         */
        inline bool IsLoaded() const { return m_Loaded; }

    protected:
        /**
         * @brief The custom resource loading process
         *      This is the place where the resource is actually loaded
         *      Other resource specific loading process should be implemented here
         *
         * @return true if the resource is loaded successfully
         *          false if the resource is failed to load
         */
        virtual bool LoadImpl();

        /**
         * @brief The custom resource unloading process
         *      This is the place where the resource is actually unloaded
         *      Other resource specific unloading process should be implemented here
         */
        virtual void UnloadImpl();

    private:
        /**
         * @brief The resource ID
         */
        uint8_t m_RID;
        /**
         * @brief The resource scope
         *  0 - Global
         *  1 -> n - Scene specific (n is the number of scenes in the game)
         */
        uint8_t m_Scope;
        /**
         * @brief The resource file path
         *
         * This is the absolute path to the resource file
         */
        std::string m_FilePath;
        /**
         * @brief The resource type
         */
        ResourceType m_Type;

        /**
         * @brief The flag to indicate whether the resource is loaded (false as default)
         */
        bool m_Loaded;
    };
} // namespace ntt

#include <NTTEngine/GraphicManager/GraphicResource.hpp>
#include <SFML/Graphics.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <NTTEngine/GraphicManager/GraphicManager.hpp>

namespace ntt
{
    GraphicResource::GraphicResource(uint8_t rid, uint8_t scope,
                                     const std::string &filePath)
        : ResourceObject(rid, scope, filePath, ResourceType::RT_GRAPHICS),
          m_Sprite(nullptr), m_Texture(nullptr)
    {
    }

    GraphicResource::~GraphicResource()
    {
    }

    bool GraphicResource::LoadImpl()
    {
        m_Texture = new sf::Texture();
        if (!m_Texture->loadFromFile(GetFilePath()))
        {
            LOG_ERROR("Failed to load resource: " + std::to_string(GetRID()));
            return false;
        }

        m_Sprite = new sf::Sprite(*m_Texture);

        LOG_INFO("Loaded resource: " + std::to_string(GetRID()));
        LOG_INFO("Texture size: " + std::to_string(m_Texture->getSize().x) + "x" + std::to_string(m_Texture->getSize().y));
        return true;
    }

    void GraphicResource::UnloadImpl()
    {
        LOG_INFO("Unloaded resource: " + std::to_string(GetRID()));
        delete m_Texture;
        delete m_Sprite;
    }
} // namespace ntt

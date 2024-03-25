#pragma once
#include <NTTEngine/ResourceManager/ResourceManager.hpp>
#include <SFML/Graphics.hpp>

namespace ntt
{
    class GraphicResource : public ResourceObject
    {
    public:
        GraphicResource(uint8_t rid, uint8_t scope,
                        const std::string &filePath);

        virtual ~GraphicResource();
        inline int GetWidth() const { return m_Texture != nullptr ? m_Texture->getSize().x : 0; }
        inline int GetHeight() const { return m_Texture != nullptr ? m_Texture->getSize().y : 0; }
        inline sf::Sprite &GetSprite() { return *m_Sprite; }

    protected:
        bool LoadImpl() override;
        void UnloadImpl() override;

    private:
        sf::Sprite *m_Sprite;
        sf::Texture *m_Texture;
    };
} // namespace ntt

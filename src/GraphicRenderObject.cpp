#include <NTTEngine/GraphicManager/GraphicRenderObject.hpp>
#include <NTTEngine/ResourceManager/ResourceManager.hpp>
#include <NTTEngine/GraphicManager/GraphicManager.hpp>
#include <SFML/Graphics.hpp>

namespace ntt
{
    GraphicRenderObject::GraphicRenderObject(uint8_t rid)
        : m_RID(rid)
    {
    }

    void GraphicRenderObject::Draw(int x, int y)
    {
        auto resource = GET_RESOURCE_BY_ID(m_RID);
        if (resource != nullptr && resource->IsLoaded())
        {
            auto graphicResource = Cast<GraphicResource>(resource);
            auto sprite = graphicResource->GetSprite();
            sprite.setPosition(sf::Vector2f(x, y));

            auto window = static_cast<sf::RenderWindow *>(GetGraphicManager()->GetWindow());
            window->draw(sprite);
        }
    }
} // namespace ntt

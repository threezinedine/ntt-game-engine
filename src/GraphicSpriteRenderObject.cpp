#include <NTTEngine/GraphicManager/GraphicSpriteRenderObject.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>

namespace ntt
{
	GraphicSpriteRenderObject::GraphicSpriteRenderObject(uint8_t rid, int frameHeight,
														 int frameWidth,
														 unsigned int changePerMilliseconds)
		: GraphicRenderObject(rid), m_FrameHeight(frameHeight),
		  m_FrameWidth(frameWidth),
		  m_CurrentFrameRowIndex(0),
		  m_CurrentFrameColIndex(0),
		  m_IsPlaying(false),
		  m_TimeTrigger(changePerMilliseconds)
	{
		auto resource = GET_RESOURCE_BY_ID(rid);

		if (resource != nullptr && resource->IsLoaded())
		{
			auto graphicResource = Cast<GraphicResource>(resource);
			m_Row = graphicResource->GetHeight() / frameHeight;
			m_Col = graphicResource->GetWidth() / frameWidth;
			LOG_DEBUG("Graphic resource size: " + std::to_string(graphicResource->GetWidth()) + "x" + std::to_string(graphicResource->GetHeight()));
			LOG_DEBUG("Row: " + std::to_string(m_Row) + " Col: " + std::to_string(m_Col));
		}
		else
		{
			m_Row = 0;
			m_Col = 0;
		}

		m_TimeTrigger.Reset();
	}

	void GraphicSpriteRenderObject::Play()
	{
		m_IsPlaying = true;
	}

	void GraphicSpriteRenderObject::Stop()
	{
		m_IsPlaying = false;
	}

	void GraphicSpriteRenderObject::Update()
	{
	}

	void GraphicSpriteRenderObject::NextFrame()
	{
		if (m_CurrentFrameRowIndex == m_Row - 1 && m_CurrentFrameColIndex == m_Col - 1)
		{
			m_CurrentFrameRowIndex = 0;
			m_CurrentFrameColIndex = 0;
		}
		else if (m_CurrentFrameColIndex == m_Col - 1)
		{
			m_CurrentFrameColIndex = 0;
			m_CurrentFrameRowIndex++;
		}
		else
		{
			m_CurrentFrameColIndex++;
		}
	}

	void GraphicSpriteRenderObject::Draw(int x, int y)
	{
		auto resource = GET_RESOURCE_BY_ID(GetRID());

		if (resource != nullptr && resource->IsLoaded())
		{
			auto graphicResource = Cast<GraphicResource>(resource);

			sf::IntRect portion(sf::Vector2(m_CurrentFrameColIndex * m_FrameWidth,
											m_CurrentFrameRowIndex * m_FrameHeight),
								sf::Vector2(m_FrameWidth, m_FrameHeight));

			auto sprite = graphicResource->GetSprite();
			sprite.setTextureRect(portion);
			sprite.setPosition(sf::Vector2f(x, y));

			auto window = static_cast<sf::RenderWindow *>(GetGraphicManager()->GetWindow());
			window->draw(sprite);

			if (m_IsPlaying && m_TimeTrigger.IsTriggered())
			{
				NextFrame();
				m_TimeTrigger.Reset();
			}
		}
	}
} // namespace ntt

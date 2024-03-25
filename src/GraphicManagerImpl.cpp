#define SDL_MAIN_HANDLED
#include <NTTEngine/GraphicManager/GraphicManagerImpl.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <SFML/Graphics.hpp>
#include <NTTEngine/ResourceManager/ResourceManager.hpp>
#include <NTTEngine/GraphicManager/GraphicResource.hpp>
#include <NTTEngine/GraphicManager/GraphicRenderObject.hpp>
#include <NTTEngine/GraphicManager/GraphicSpriteRenderObject.hpp>

namespace ntt
{
    GraphicManagerImpl *GraphicManagerImpl::m_Ins = nullptr;

    GraphicManagerImpl::GraphicManagerImpl()
        : m_Width(0), m_Height(0), m_Title(""), m_FullScreen(false),
          m_ShouldWindowClosed(false), m_Window(nullptr)
    {
    }

    GraphicManagerImpl::~GraphicManagerImpl()
    {
        delete m_Window;
    }

    void GraphicManagerImpl::NewWindow(unsigned int width, unsigned int height,
                                       const std::string &title,
                                       bool fullScreen)
    {
        m_Width = width;
        m_Height = height;
        m_Title = title;
        m_FullScreen = fullScreen;

        m_Window = new sf::RenderWindow(sf::VideoMode(sf::Vector2(width, height)), title);
        m_Window->setFramerateLimit(60);
    }

    void GraphicManagerImpl::Update()
    {
        sf::Event event;

        while (m_Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                LOG_INFO("Quit event detected");
                m_Window->close();
                return;
            }
        }
    }

    void GraphicManagerImpl::BeginFrame()
    {
        m_Window->clear(sf::Color::Black);
    }

    void GraphicManagerImpl::EndFrame()
    {
        m_Window->display();
    }

    void GraphicManagerImpl::Draw(uint8_t rid, float x, float y)
    {
        if (m_RenderObjects.find(rid) == m_RenderObjects.end())
        {
            auto renderObject = MakeRef<GraphicRenderObject>(rid);
            m_RenderObjects[rid] = renderObject;
        }

        m_RenderObjects[rid]->Draw(x, y);
    }

    void GraphicManagerImpl::DrawSprite(uint8_t rid, float x, float y,
                                        float frameWidth, float frameHeight,
                                        unsigned int changePerMiliseconds)
    {
        if (m_RenderObjects.find(rid) == m_RenderObjects.end())
        {
            auto renderObject = MakeRef<GraphicSpriteRenderObject>(rid, frameWidth,
                                                                   frameHeight, changePerMiliseconds);
            Cast<GraphicSpriteRenderObject>(renderObject)->Play();
            m_RenderObjects[rid] = renderObject;
        }

        m_RenderObjects[rid]->Draw(x, y);
    }

    void GraphicManagerImpl::InitGraphicManagerIns()
    {
        if (m_Ins == nullptr)
        {
            m_Ins = new GraphicManagerImpl();
        }
    }

    GraphicManagerImpl *GraphicManagerImpl::GetGraphicManagerIns()
    {
        return m_Ins;
    }

    void GraphicManagerImpl::ReleaseGraphicManagerIns()
    {
        delete m_Ins;
        m_Ins = nullptr;
    }

    void InitGraphicManager()
    {
        GraphicManagerImpl::InitGraphicManagerIns();
    }

    GraphicManager *GetGraphicManager()
    {
        return GraphicManagerImpl::GetGraphicManagerIns();
    }

    void ReleaseGraphicManager()
    {
        GraphicManagerImpl::ReleaseGraphicManagerIns();
    }
} // namespace ntt

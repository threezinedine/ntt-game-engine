#include <NTTEngine/GraphicManager/GraphicManagerImpl.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <SDL3/SDL.h>
#include <NTTEngine/ResourceManager/ResourceManager.hpp>
#include <NTTEngine/GraphicManager/GraphicResource.hpp>

namespace ntt
{
    GraphicManagerImpl *GraphicManagerImpl::m_Ins = nullptr;

    GraphicManagerImpl::GraphicManagerImpl()
        : m_Width(0), m_Height(0), m_Title(""), m_FullScreen(false),
          m_ShouldWindowClosed(false), m_Window(nullptr),
          m_Renderer(nullptr)
    {
    }

    GraphicManagerImpl::~GraphicManagerImpl()
    {
        SDL_DestroyRenderer(m_Renderer);
        SDL_DestroyWindow(m_Window);
        IMG_Quit();
        SDL_Quit();
    }

    void GraphicManagerImpl::NewWindow(unsigned int width, unsigned int height,
                                       const std::string &title,
                                       bool fullScreen)
    {
        m_Width = width;
        m_Height = height;
        m_Title = title;
        m_FullScreen = fullScreen;

        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::stringstream ss;
            ss << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return;
        }

        // Create window
        m_Window = SDL_CreateWindow(m_Title.c_str(), m_Width, m_Height, SDL_EVENT_WINDOW_SHOWN);

        if (m_Window == nullptr)
        {
            std::stringstream ss;
            ss << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return;
        }

        // Create renderer for window
        m_Renderer = SDL_CreateRenderer(m_Window, NULL, SDL_RENDERER_ACCELERATED);
        if (m_Renderer == nullptr)
        {
            std::stringstream ss;
            ss << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return;
        }

        // Init PNG loading
        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        {
            std::stringstream ss;
            ss << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return;
        }
    }

    void GraphicManagerImpl::Update()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                LOG_INFO("Quit event detected");
                m_ShouldWindowClosed = true;
                return;
            }
        }
    }

    void GraphicManagerImpl::BeginFrame()
    {
        SDL_RenderClear(m_Renderer);
    }

    void GraphicManagerImpl::EndFrame()
    {
        SDL_RenderPresent(m_Renderer);
    }

    void GraphicManagerImpl::Draw(uint8_t id, float x, float y)
    {
        auto resource = GET_RESOURCE_BY_ID(id);
        if (resource != nullptr && resource->IsLoaded())
        {
            auto graphicResource = Cast<GraphicResource>(resource);
            SDL_FRect rect = {x, y, graphicResource->GetWidth(), graphicResource->GetHeight()};

            SDL_RenderTexture(m_Renderer, graphicResource->GetTexture(), NULL, &rect);
        }
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

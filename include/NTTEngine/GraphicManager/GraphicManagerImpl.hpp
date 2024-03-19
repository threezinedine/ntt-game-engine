#pragma once

#include <NTTEngine/GraphicManager/GraphicManager.hpp>
#include <SDL3/SDL.h>

namespace ntt
{
    class GraphicManagerImpl : public GraphicManager
    {
    public:
        ~GraphicManagerImpl();
        void NewWindow(unsigned int width, unsigned int height,
                       const std::string &title,
                       bool fullScreen = false) override;
        void Update() override;
        inline bool ShouldWindowClosed() override { return m_ShouldWindowClosed; }

        void Draw(uint8_t id, float x, float y) override;
        void BeginFrame() override;
        void EndFrame() override;
        inline void *GetRenderer() override { return m_Renderer; }

        static void InitGraphicManagerIns();
        static GraphicManagerImpl *GetGraphicManagerIns();
        static void ReleaseGraphicManagerIns();

    protected:
        GraphicManagerImpl();

    private:
        unsigned int m_Width;
        unsigned int m_Height;
        std::string m_Title;
        bool m_FullScreen;

        bool m_ShouldWindowClosed;

        SDL_Window *m_Window;
        SDL_Renderer *m_Renderer;

        static GraphicManagerImpl *m_Ins;
    };
} // namespace ntt

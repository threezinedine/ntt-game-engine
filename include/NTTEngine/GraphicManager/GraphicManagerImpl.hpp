#pragma once

#include <NTTEngine/GraphicManager/GraphicManager.hpp>
#include <SFML/Graphics.hpp>
#include "GraphicRenderObject.hpp"

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
        inline bool ShouldWindowClosed() override { return !m_Window->isOpen(); }

        void Draw(uint8_t rid, float x, float y) override;
        void DrawSprite(uint8_t rid, float x, float y, float frameWidth,
                        float frameHeight, unsigned int changePerMiliseconds) override;
        void BeginFrame() override;
        void EndFrame() override;
        inline void *GetWindow() override { return m_Window; }

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

        sf::RenderWindow *m_Window;

        Dictionary<uint8_t, Ref<GraphicRenderObject>> m_RenderObjects;

        static GraphicManagerImpl *m_Ins;
    };
} // namespace ntt

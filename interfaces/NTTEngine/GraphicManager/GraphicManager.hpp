#pragma once

#include <NTTEngine/Common.hpp>
#include <NTTEngine/EngineObject.hpp>

namespace ntt
{
    class GraphicManager : public EngineObject
    {
    public:
        virtual ~GraphicManager() = default;

        virtual void NewWindow(unsigned int width, unsigned int height,
                               const std::string &title,
                               bool fullScreen = false) = 0;
        virtual void Update() = 0;
        virtual bool ShouldWindowClosed() = 0;

        virtual void Draw(uint8_t rid, float x, float y) = 0;
        virtual void DrawSprite(uint8_t rid, float x, float y,
                                float frameWidth, float frameHeight,
                                unsigned int changePerMiliseconds) = 0;
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;
        virtual void *GetWindow() = 0;
    };

    void InitGraphicManager();
    GraphicManager *GetGraphicManager();
    void ReleaseGraphicManager();
} // namespace ntt

#define INIT_GRAPHIC_MANAGER() ntt::InitGraphicManager()
#define GET_GRAPHIC_MANAGER() ntt::GetGraphicManager()
#define RELEASE_GRAPHIC_MANAGER() ntt::ReleaseGraphicManager()

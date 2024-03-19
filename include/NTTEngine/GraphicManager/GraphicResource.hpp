#pragma once
#include <NTTEngine/ResourceManager/ResourceManager.hpp>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace ntt
{
    class GraphicResource : public ResourceObject
    {
    public:
        GraphicResource(uint8_t rid, uint8_t scope,
                        const std::string &filePath);

        virtual ~GraphicResource();
        inline float GetWidth() const { return static_cast<float>(m_Width); }
        inline float GetHeight() const { return static_cast<float>(m_Height); }
        inline SDL_Texture *GetTexture() const { return m_Texture; }

    protected:
        bool LoadImpl() override;
        void UnloadImpl() override;

    private:
        SDL_Texture *m_Texture;
        int m_Width;
        int m_Height;
    };
} // namespace ntt

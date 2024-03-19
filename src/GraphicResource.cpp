#include <NTTEngine/GraphicManager/GraphicResource.hpp>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <NTTEngine/GraphicManager/GraphicManager.hpp>

namespace ntt
{
    GraphicResource::GraphicResource(uint8_t rid, uint8_t scope,
                                     const std::string &filePath)
        : ResourceObject(rid, scope, filePath, ResourceType::RT_GRAPHICS)
    {
    }

    GraphicResource::~GraphicResource()
    {
    }

    bool GraphicResource::LoadImpl()
    {
        // Load the image from the file using the sdl_image library
        SDL_Surface *surface = IMG_Load(GetFilePath().c_str());

        if (surface == nullptr)
        {
            std::stringstream ss;
            ss << "Unable to load image " << GetFilePath() << "! SDL_image Error: " << IMG_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return false;
        }

        // Create a texture from the surface
        m_Texture = SDL_CreateTextureFromSurface(
            static_cast<SDL_Renderer *>(GetGraphicManager()->GetRenderer()),
            surface);

        if (m_Texture == nullptr)
        {
            std::stringstream ss;
            ss << "Unable to create texture from " << GetFilePath() << "! SDL Error: " << SDL_GetError() << std::endl;
            LOG_ERROR(ss.str());
            return false;
        }

        SDL_QueryTexture(m_Texture, NULL, NULL, &m_Width, &m_Height);

        // clear the surface
        SDL_DestroySurface(surface);

        LOG_DEBUG("Load resource: " + std::to_string(GetRID()) + " successfully");

        return true;
    }

    void GraphicResource::UnloadImpl()
    {
        if (m_Texture != nullptr)
        {
            LOG_DEBUG("is texture null? " + std::to_string(m_Texture == nullptr));
            SDL_DestroyTexture(m_Texture);
            LOG_DEBUG("Unload resource: " + std::to_string(GetRID()) + " successfully");
            m_Texture = nullptr;
        }
    }
} // namespace ntt

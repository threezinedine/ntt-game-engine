#pragma once

#include "GraphicResource.hpp"
#include <NTTEngine/GraphicManager/GraphicManager.hpp>

namespace ntt
{
    class GraphicRenderObject : public EngineObject
    {
    public:
        GraphicRenderObject(uint8_t rid);
        virtual ~GraphicRenderObject() = default;

        inline uint8_t GetRID() const { return m_RID; }

        virtual void Draw(int x, int y, unsigned int width = -1, unsigned int height = -1);

    private:
        uint8_t m_RID;
    };
} // namespace ntt

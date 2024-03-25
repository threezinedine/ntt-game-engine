#pragma once

#include "GraphicRenderObject.hpp"
#include <NTTEngine/TimeUtils/TimeUtils.hpp>

namespace ntt
{
    class GraphicSpriteRenderObject : public GraphicRenderObject
    {
    public:
        GraphicSpriteRenderObject(uint8_t rid, int frameHeight, int frameWidth,
                                  unsigned int changePerMilliseconds = 1);

        virtual ~GraphicSpriteRenderObject() = default;

        void Play();
        void Stop();
        void Update();

        virtual void Draw(int x, int y) override;

    protected:
        void NextFrame();

    private:
        uint8_t m_RID;
        int m_FrameHeight;
        int m_FrameWidth;
        int m_Row;
        int m_Col;

        int m_CurrentFrameRowIndex;
        int m_CurrentFrameColIndex;

        bool m_IsPlaying;
        TimeTrigger m_TimeTrigger;
    };
} // namespace ntt

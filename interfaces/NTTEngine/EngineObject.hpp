#pragma once

namespace ntt
{
    class EngineObject
    {
    public:
        EngineObject();
        virtual ~EngineObject();

        inline int GetId() const { return m_Id; };

    private:
        int m_Id;
    };
} // namespace ntt

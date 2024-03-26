#pragma once

namespace ntt
{
    class TimeTrigger
    {
    public:
        TimeTrigger(unsigned int timeInMilliseconds);
        ~TimeTrigger();

        void Reset();
        bool IsTriggered();

    private:
        unsigned int m_TimeInMilliseconds;
        long long m_StartTime;
    };
} // namespace ntt

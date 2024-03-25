#include "NTTEngine/TimeUtils/TimeUtils.hpp"
#include <chrono>

namespace ntt
{
    TimeTrigger::TimeTrigger(unsigned int timeInMilliseconds)
        : m_TimeInMilliseconds(timeInMilliseconds), m_StartTime(0)
    {
    }

    TimeTrigger::~TimeTrigger()
    {
    }

    void TimeTrigger::Reset()
    {
        m_StartTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::system_clock::now().time_since_epoch())
                          .count();
    }

    bool TimeTrigger::IsTriggered()
    {
        auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                               std::chrono::system_clock::now().time_since_epoch())
                               .count();

        return currentTime - m_StartTime >= m_TimeInMilliseconds;
    }
} // namespace ntt

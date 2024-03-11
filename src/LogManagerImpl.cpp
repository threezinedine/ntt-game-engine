#include <NTTEngine/LogManager/LogManagerImpl.hpp>

namespace ntt
{
    LogManagerImpl LogManagerImpl::m_Ins;

    LogManagerImpl::LogManagerImpl()
    {
    }

    LogManagerImpl::~LogManagerImpl()
    {
    }

    void LogManagerImpl::Info(LogMessage message)
    {
        std::cout << "[INFO]" << message.ToString() << std::endl;
    }

    void LogManagerImpl::Debug(LogMessage message)
    {
    }

    void LogManagerImpl::Warn(LogMessage message)
    {
    }

    void LogManagerImpl::Error(LogMessage message)
    {
    }

    void LogManagerImpl::Fatal(LogMessage message)
    {
    }

    LogManager *GetLogManager()
    {
        return LogManagerImpl::GetLogManagerIns();
    }
} // namespace ntt

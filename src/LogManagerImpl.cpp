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
        std::cout << "[INFO] " << message.ToString() << std::endl;
    }

    void LogManagerImpl::Debug(LogMessage message)
    {
        std::cout << "[DEBUG] " << message.ToString() << std::endl;
    }

    void LogManagerImpl::Warn(LogMessage message)
    {
        std::cout << "[WARN] " << message.ToString() << std::endl;
    }

    void LogManagerImpl::Error(LogMessage message)
    {
        std::cout << "[ERROR] " << message.ToString() << std::endl;
    }

    void LogManagerImpl::Fatal(LogMessage message)
    {
        std::cout << "[FATAL] " << message.ToString() << std::endl;
    }

    LogManager *GetLogManager()
    {
        return LogManagerImpl::GetLogManagerIns();
    }
} // namespace ntt

#include <NTTEngine/Common/Common.hpp>
#include <NTTEngine/LogManager/LogManager.hpp>
#include <NTTENGINE/LogManager/LogManagerImpl.hpp>

namespace ntt::log
{
    LogManagerImpl::LogManagerImpl()
    {
    }

    LogManagerImpl::~LogManagerImpl()
    {
    }

    void LogManagerImpl::Info(const char *message)
    {
        std::cout << "Info: " << message << std::endl;
    }

    void LogManagerImpl::Debug(const char *message)
    {
        std::cout << "Debug: " << message << std::endl;
    }

    void LogManagerImpl::Warn(const char *message)
    {
        std::cout << "Warn: " << message << std::endl;
    }

    void LogManagerImpl::Error(const char *message)
    {
        std::cout << "Error: " << message << std::endl;
    }

    void LogManagerImpl::Fatal(const char *message)
    {
        std::cout << "Fatal: " << message << std::endl;
    }

} // namespace ntt::log

static ntt::log::LogManager *m_Ins = nullptr;

void InitLogManager()
{
    m_Ins = new ntt::log::LogManagerImpl();
}

ntt::log::LogManager *GetLogManagerInstance()
{
    if (m_Ins == nullptr)
    {
        InitLogManager();
    }
    return m_Ins;
}

void ReleaseLogManager()
{
    if (m_Ins != nullptr)
    {
        delete m_Ins;
        m_Ins = nullptr;
    }
}

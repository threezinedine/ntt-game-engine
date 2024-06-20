#pragma once
#include <NTTEngine/LogManager/LogManager.hpp>

namespace ntt::log
{
    class LogManagerImpl : public LogManager
    {
    public:
        LogManagerImpl();
        ~LogManagerImpl() override;

        void Info(const char *message) override;
        void Debug(const char *message) override;
        void Warn(const char *message) override;
        void Error(const char *message) override;
        void Fatal(const char *message) override;
    };
} // namespace ntt::log

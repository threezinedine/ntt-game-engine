#pragma once

#include <NTTEngine/EngineObject.hpp>
#include "LogMessage.hpp"

namespace ntt
{
    class LogManager : public EngineObject
    {
    public:
        virtual ~LogManager() = default;

        virtual void Info(LogMessage message) = 0;
        virtual void Debug(LogMessage message) = 0;
        virtual void Warn(LogMessage message) = 0;
        virtual void Error(LogMessage message) = 0;
        virtual void Fatal(LogMessage message) = 0;
    };

    LogManager *GetLogManager();
} // namespace ntt

#define LOG_INFO(message) ntt::GetLogManager()->Info(ntt::LogMessage(__FILE__, __LINE__, message))
#define LOG_DEBUG(message) ntt::GetLogManager()->Debug(ntt::LogMessage(__FILE__, __LINE__, message))
#define LOG_WARN(message) ntt::GetLogManager()->Warn(ntt::LogMessage(__FILE__, __LINE__, message))
#define LOG_ERROR(message) ntt::GetLogManager()->Error(ntt::LogMessage(__FILE__, __LINE__, message))
#define LOG_FATAL(message) ntt::GetLogManager()->Fatal(ntt::LogMessage(__FILE__, __LINE__, message))

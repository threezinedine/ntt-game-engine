#pragma once
#include <LibraryLoader.hpp>

namespace ntt::log
{
    class LogManager
    {
    public:
        virtual ~LogManager() = default;
        virtual void Info(const char *message) = 0;
        virtual void Debug(const char *message) = 0;
        virtual void Warn(const char *message) = 0;
        virtual void Error(const char *message) = 0;
        virtual void Fatal(const char *message) = 0;
    };
} // namespace ntt::log

extern "C"
{
    void InitLogManager();
    ntt::log::LogManager *GetLogManagerInstance();
    void ReleaseLogManager();
}

#define LOG_LOAD(path) ntt::loader::LibraryLoader<ntt::log::LogManager> loader(path, "LogManager")
#define LOG_INIT() loader.Init()

#define LOG_INFO(message) loader.GetInstance()->Info(message)
#define LOG_DEBUG(message) loader.GetInstance()->Debug(message)
#define LOG_WARN(message) loader.GetInstance()->Warn(message)
#define LOG_ERROR(message) loader.GetInstance()->Error(message)
#define LOG_FATAL(message) loader.GetInstance()->Fatal(message)

#define LOG_INFO_F(format, ...) loader.GetInstance()->Info(ntt::string::String(format, __VA_ARGS__).GetValue())
#define LOG_DEBUG_F(format, ...) loader.GetInstance()->Debug(ntt::string::String(format, __VA_ARGS__).GetValue())
#define LOG_WARN_F(format, ...) loader.GetInstance()->Warn(ntt::string::String(format, __VA_ARGS__).GetValue())
#define LOG_ERROR_F(format, ...) loader.GetInstance()->Error(ntt::string::String(format, __VA_ARGS__).GetValue())
#define LOG_FATAL_F(format, ...) loader.GetInstance()->Fatal(ntt::string::String(format, __VA_ARGS__).GetValue())

#define LOG_RELEASE() loader.Release()
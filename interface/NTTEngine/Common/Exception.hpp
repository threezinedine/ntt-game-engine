#pragma once
#include <exception>
#include "String.hpp"
#include <cstdarg>

// TODO: Remove later
#include <iostream>

namespace ntt::exception
{
    class Exception : public std::exception
    {
    public:
        Exception() : m_Message("Unknown exception") {}
        Exception(const char *message) : m_Message(message) {}
        virtual ~Exception() noexcept override = default;

        virtual const char *what() const noexcept override
        {
            return m_Message;
        }

    private:
        const char *m_Message;
    };

    class FormatException : public Exception
    {
    public:
        FormatException(const char *format, ...)
        {
            va_list args;
            va_start(args, format);
            size_t size = std::vsnprintf(nullptr, 0, format, args) + 1; // Extra space for '\0'
            va_end(args);
            m_Message.resize(size);
            va_start(args, format);
            std::vsnprintf(&m_Message[0], size, format, args);
            va_end(args);
        }
        virtual ~FormatException() noexcept override = default;

        virtual const char *what() const noexcept override
        {
            return m_Message.c_str();
        }

    private:
        std::string m_Message;
    };
} // namespace ntt::exception

#define THROW_EXCEPTION(message) throw ntt::exception::Exception(message)
#define THROW_EXCEPTION_F(format, ...) throw ntt::exception::FormatException(format, __VA_ARGS__)
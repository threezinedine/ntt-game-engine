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
        Exception(const ntt::string::String &message) : m_Message(message.GetValue()) {}
        virtual ~Exception() noexcept override = default;

        virtual const char *what() const noexcept override
        {
            return m_Message.c_str();
        }

    private:
        std::string m_Message;
    };
} // namespace ntt::exception

#define THROW_EXCEPTION(message) throw ntt::exception::Exception(message)
#define THROW_EXCEPTION_F(format, ...) throw ntt::exception::Exception(ntt::string::String(format, __VA_ARGS__))
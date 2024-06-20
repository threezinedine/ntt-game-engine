#pragma once
#include <string>
#include <cstring>
#include <cstdarg>

// TODO: remove later
#include <iostream>

namespace ntt::string
{
    class String
    {
    public:
        String(const char *format, ...)
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

        ~String() = default;

        inline const char *GetValue() const { return m_Message.c_str(); }

    private:
        std::string m_Message;
    };
} // namespace ntt::string

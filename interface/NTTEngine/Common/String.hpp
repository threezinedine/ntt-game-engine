#pragma once
#include <string>
#include <cstring>

// TODO: remove later
#include <iostream>

namespace ntt::string
{
    template <typename... Args>
    class String
    {
    public:
        String(const char *format, Args... args)
        {
            m_Buffer = new char[snprintf(nullptr, 0, format, args...) + 1];
            sprintf(m_Buffer, format, args...);
        }

        ~String()
        {
            delete[] m_Buffer;
        }

        inline const char *GetValue() const { return m_Buffer; }

    private:
        char *m_Buffer;
    };
} // namespace ntt::string

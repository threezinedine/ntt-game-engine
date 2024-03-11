#pragma once
#include <NTTEngine/Common.hpp>
#include <NTTEngine/EngineObject.hpp>

namespace ntt
{
    class LogMessage : public EngineObject
    {
    public:
        LogMessage(std::string fileName, unsigned int line, std::string message)
            : m_File(fileName), m_Line(line), m_Message(message)
        {
        }

        ~LogMessage() {}

        inline const std::string &GetMessage() const { return m_Message; }
        inline const std::string &GetFile() const { return m_File; }
        inline unsigned int GetLine() const { return m_Line; }

        std::string ToString();

    private:
        std::string m_File;
        unsigned int m_Line;
        std::string m_Message;
    };
} // namespace ntt

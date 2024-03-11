#include <NTTEngine/LogManager/LogMessage.hpp>

namespace ntt
{
    std::string LogMessage::ToString()
    {
        std::stringstream ss;

        ss << GetFile() << ":" << GetLine() << " - " << GetMessage();
        return ss.str();
    }
} // namespace ntt

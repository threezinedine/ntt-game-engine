#include <NTTEngine/LogManager/LogManager.hpp>

namespace ntt
{
    class LogManagerImpl : public LogManager
    {
    public:
        void Info(LogMessage message);
        void Debug(LogMessage message);
        void Warn(LogMessage message);
        void Error(LogMessage message);
        void Fatal(LogMessage message);

        static LogManagerImpl *GetLogManagerIns() { return m_Ins; }
        static void InitLogManagerIns();
        static void ReleaseLogManagerIns();

    protected:
        LogManagerImpl();
        ~LogManagerImpl();

    private:
        static LogManagerImpl *m_Ins;
    };
} // namespace ntt

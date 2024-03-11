#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    ntt::GetLogManager()->Info(ntt::LogMessage("testing", 12, "Hello world"));
    return 0;
}
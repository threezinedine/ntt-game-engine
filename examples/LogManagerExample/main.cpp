#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    INIT_LOG_MANAGER();
    LOG_INFO("Hello world");
    LOG_WARN("Hello world");
    RELEASE_LOG_MANAGER();
    return 0;
}
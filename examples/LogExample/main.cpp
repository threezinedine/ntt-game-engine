#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    LOG_LOAD("C:/Users/Acer/C/ntt-game-engine/build/libntt-game-engine.dll");
    LOG_INIT();

    LOG_INFO("Hello, World!");

    LOG_DEBUG_F("Hello, %s!", "World");

    try
    {
        THROW_EXCEPTION("This is an exception");
    }
    catch (const ntt::exception::Exception &e)
    {
        LOG_ERROR(e.what());
    }

    try
    {
        THROW_EXCEPTION_F("This is an exception with format %d", 1);
    }
    catch (const ntt::exception::Exception &e)
    {
        LOG_FATAL(e.what());
    }

    try
    {
        THROW_EXCEPTION_F("This is an exception %s", "Thao");
    }
    catch (const ntt::exception::Exception &e)
    {
        LOG_ERROR(e.what());
    }

    LOG_RELEASE();
    return 0;
}
#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    INIT_LOG_MANAGER();
    INIT_RESOURCE_MANAGER();
    LOG_INFO("Initializing ...");

    LOAD_RESOURCES("C:/Users/Acer/C_Language/ntt-game-engine/examples/"
                   "ResourceManagerExample/resources.json");

    SET_SCOPE(1);

    SET_SCOPE(2);

    SET_SCOPE(0);

    RELEASE_RESOURCE_MANAGER();

    LOG_INFO("Releasing ...");
    RELEASE_LOG_MANAGER();
    return 0;
}
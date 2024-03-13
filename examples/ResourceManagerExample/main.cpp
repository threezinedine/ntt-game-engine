#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    LOG_INFO("Initializing ...");

    LOAD_RESOURCES("C:/Users/Acer/C_Language/ntt-game-engine/examples/"
                   "ResourceManagerExample/resources.json");

    SET_SCOPE(1);

    LOG_INFO("Releasing ...");
    return 0;
}
#define SDL_MAIN_HANDLED
#include <NTTEngine/NTTEngine.hpp>

int main(int argc, char **argv)
{
    INIT_LOG_MANAGER();
    INIT_RESOURCE_MANAGER();
    INIT_GRAPHIC_MANAGER();

    LOG_INFO("testing");

    GET_GRAPHIC_MANAGER()->NewWindow(800, 600, "Test Window");
    LOAD_RESOURCES("C:/Users/Acer/C_Language/ntt-game-engine/examples/GraphicManagerExample/resources.json");

    try
    {
        while (!GET_GRAPHIC_MANAGER()->ShouldWindowClosed())
        {
            GET_GRAPHIC_MANAGER()->Update();
            GET_GRAPHIC_MANAGER()->BeginFrame();

            // GET_GRAPHIC_MANAGER()->Draw(1, 100, 100);
            // GET_GRAPHIC_MANAGER()->Draw(2, 0, 0);
            GET_GRAPHIC_MANAGER()->DrawSprite(2, 100, 100, 16, 16, 10000);

            GET_GRAPHIC_MANAGER()->EndFrame();
        }
    }
    catch (const std::exception &e)
    {
        LOG_ERROR(e.what());
    }

    UNLOAD_RESOURCES();

    RELEASE_GRAPHIC_MANAGER();
    RELEASE_RESOURCE_MANAGER();
    RELEASE_LOG_MANAGER();
    return 0;
}
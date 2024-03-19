#include <NTTEngine/NTTEngine.hpp>

int main(void)
{
    INIT_LOG_MANAGER();
    INIT_RESOURCE_MANAGER();
    INIT_GRAPHIC_MANAGER();

    LOG_INFO("testing");

    GET_GRAPHIC_MANAGER()->NewWindow(800, 600, "Test Window");
    LOAD_RESOURCES("C:/Users/Acer/C_Language/ntt-game-engine/examples/GraphicManagerExample/resources.json");

    while (!GET_GRAPHIC_MANAGER()->ShouldWindowClosed())
    {
        GET_GRAPHIC_MANAGER()->Update();
        GET_GRAPHIC_MANAGER()->BeginFrame();

        GET_GRAPHIC_MANAGER()->Draw(1, 30, 30);

        GET_GRAPHIC_MANAGER()->EndFrame();
    }

    UNLOAD_RESOURCES();

    RELEASE_GRAPHIC_MANAGER();
    RELEASE_RESOURCE_MANAGER();
    RELEASE_LOG_MANAGER();
    return 0;
}
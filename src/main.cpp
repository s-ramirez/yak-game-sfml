#include <yak.hpp>

using namespace Yak;

int main()
{
    // Init game engine
    Game game;

    Config game_config;
    game_config.name = "Legend of Zelda";
    game_config.width = 800;
    game_config.height = 640;

    game.Init(game_config);

    while (game.isRunning())
    {
        game.Update();
        game.Render();
    }

    return 0;
}

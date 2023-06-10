#pragma once

#include <SFML/Graphics.hpp>

#include "common/config.hpp"

/*
    Main game engine wrapper class
*/
namespace Yak
{
    class Game
    {
    public:
        // Constructors
        Game();
        ~Game();

        // Functions
        void Init(const Config config);
        void Update();
        void Render();
        void HandleEvents();

        // Accessors
        const bool isRunning();

    private:
        // Variables
        // Window
        sf::RenderWindow *window;
        sf::Event event;
    };
}
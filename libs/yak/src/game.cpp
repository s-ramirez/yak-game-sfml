#include <yak/game.hpp>

using namespace Yak;

// Constructor/Destructor
Game::Game()
{
    this->window = nullptr;
}

Game::~Game()
{
    delete this->window;
}

// Functions
void Game::Init(const Config config)
{
    this->window = new sf::RenderWindow(sf::VideoMode(config.width, config.height), config.name, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(config.framerate);
}

void Game::HandleEvents()
{
    // Event polling
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        default:
            break;
        }
    }
}

void Game::Update()
{
    this->HandleEvents();
}

void Game::Render()
{
    this->window->clear();

    // Draw game
    this->window->display();
}

// Accessors
const bool Game::isRunning()
{
    return this->window->isOpen();
}
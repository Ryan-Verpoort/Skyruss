#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

class GameOverScreen
{
public:
    GameOverScreen();
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _EndTexture;
    sf::Font _Font;
};

#endif
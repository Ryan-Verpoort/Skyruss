#ifndef CONTROLSCREEN_H
#define CONTROLSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

class ControlScreen
{
public:
    ControlScreen();
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _ControlTexture;
    sf::Font _Font;
};

#endif
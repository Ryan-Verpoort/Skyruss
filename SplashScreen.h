#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

class SplashScreen
{
public:
    SplashScreen();
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _SplashTexture;
    sf::Font _Font;
};

#endif
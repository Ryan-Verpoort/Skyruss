#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
/**
 * @class GameOverScreen
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file GameOverScreen.h
 * @brief Game-Over Splash screeen display
 *
 * Responsible for the display of the end-of-game splash screen display once the player has either won the game, or has
 * lost
 * all in-game lives
 */

class GameOverScreen
{
public:
    /**
     * @brief Default Constructor for Game Over Splash Screen
     *
     * Responsible for loading the Universe texture from file during run-time
     */
    GameOverScreen();

    /**
     * @brief Display window renderer
     *
     * Provides the graphic information and resources neccessary for font generation used in displaying the final
     * end-of-game splash screen
     * Used also to poll the game event for terminating keys used in closing the programme, as well as the Enter key for
     * terminating the current splash screen and re-running the game
     * @param _window
     */
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _EndTexture;
    sf::Font _Font;
};

#endif
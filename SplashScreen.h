#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class SplashScreen
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file SplashScreen.h
 * @brief Initial game run-time splash screen
 *
 * Responsible for loading from file the inital pre-game splash screen to be displayed before game play begins
 */

class SplashScreen
{
public:
    /**
     * @brief Default Constructor for SplashScreen class
     */
    SplashScreen();

    /**
     * @brief Displays all information available to the user at first programme run
     *
     * Responsible for setting the title of the game - Gyruss- as well as all graphical information presented for the
     * user to read during first run
     *
     * Polls the Enter key to identify whether or not the splash screen must close to be presented with the
     * instructional
     * splashscreen
     * @param _window
     */
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _SplashTexture;
    sf::Font _Font;
};

#endif
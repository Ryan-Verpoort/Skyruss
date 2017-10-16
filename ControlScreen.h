#ifndef CONTROLSCREEN_H
#define CONTROLSCREEN_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class ControlScreen
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file ControlScreen.h
 * @brief Display window rendering
 */

class ControlScreen
{
public:
    /**
     * @brief Default Constructor for Control Screen class
     *
     * Responsible for loading Nebula control screen backdrop image from file
     */
    ControlScreen();

    /**
* @brief Responsible for all control screen graphic rendering during pre-game display
*
* Responsible for loading and displaying all graphical information to the user during pre-game run-time
* Polls the Enter key to check whether or not the control screen can be closed in order to show next display screen
* @param _window
*/
    void Display(sf::RenderWindow& _window);

private:
    sf::Texture _ControlTexture;
    sf::Font _Font;
};

#endif
#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Resources.h"
#include "Player.h"
#include <iostream>
#include "string.h"
#include "SplashScreen.h"
#include "ControlScreen.h"
#include "GameOverScreen.h"

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

/**
 * @class GamePresentation
 * @author Brandon Verkerk
 * @date 12/10/2017
 * @file GamePresentation.h
 * @brief Game Presentation class
 *
 * Responsible for the Presentation and loading of all texture objects used during run-time
 * Responsible for user input detection and keboard polling
 * Deals primarily with the use of the SFML game library as a means to ensure decoupling between the presentation and
 * logic layers of the programme
 * Sets the physical screen size to be used for the entire game
 */

class GamePresentation
{
public:
    /**
     * @brief Default Constructor for GamePresentation class
     *
     * Provides for the creation of and loading from file all sprites and textures used throughout the game
     * Used in loading the Nebula backdrop image from file to be displayed behind game-play
     * Also responsible for loading from file the Bullet texture used for displaying Player bullets
     */
    GamePresentation();
    /**
* @brief RenderWindow vector of gameObjects used for on-screen drawing during runtime
*
* Provides for the locational rendering of textures including Player craft, Enemy crafts, Satallites, Player and
* Enemy Bullets as well as in-game galaxy backrop
* @param gameObjects
*/
    void renderWindow(vector<shared_ptr<MovingObjects> >& gameObjects);

    /**
* @brief Responsible for the polling of keyboard input
*
* Used in identifying the status of assigned keys to determine and set the operation and behaviour of both
* Player position and Player Bullets
*
* This funtion includes KeyPressed and KeyReleased
*/
    void processInputEvents();

    /**
     * @brief Polls specified keys to be used as player movement commands
     *
     * This function polls the Right, Left, Space and Escape keys to enforce the behaviour of the game in a user defined
     * manner
     * Based on user input, information is passed into the releavant functions to assign game behaviour
     * @param key
     * @param isPressed
     */
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    /**
     * @brief Load textures from file
     *
     * When called, responsible for loading all textures to be used during run-time
     * These textures are called from a vector of textures stored within private member variable vector<string> _paths
     * From this, the directory path of each texture is provided
     */
    void loadTextures();
    /**
     * @brief Draw galaxy backdrop present during run-time
     */
    void drawBackground();

    /**
     * @brief Display pre-play introductory splash screen
     *
     * This screen is the first screen displayed before game-play
     */
    void UserInputs();
    void UserInputEvents(sf::Keyboard::Key key, bool isPressed);
    void Textures();
    void displayBackground();
    void displaySplashScreen();

    /**
* @brief Display pre-play control screen
*
* This screen is displayed directly before game-play outlining the controls and instructions neccessary for
* game-play
*/
    void displayControlScreen();

    /**
* @brief Display post-play Game over screen
*
* This is the final screen displayed after the game ends
*/
    void displayGameOverScreen();

    /**
    * @param Initializes the left arrow press to false to ensure that the Player craft does not move clockwise
    * unexpectedly during initial run
    */
    bool LeftKeyPressed = false;

    /**
    * @param Initializes the Right arrow press to false to ensure that the Player craft does not move anticlockwise
    * unexpectedly during initial run
    */
    bool RightKeyPressed = false;

    /**
    * @param Initializes the space key press to false to ensure that the Player craft does not shoot
    * unexpectedly during initial run
    */
    bool SpacePressed = false;

private:
    sf::RenderWindow _window;
    vector<Resources> _ObjectsTextures;
    sf::Texture _backgroundTexture;
    sf::Sprite _backgroundSprite;

    int Delay = 0;

    vector<string> _paths = { "resources/Spaceship2.png", "resources/Enemy2.png", "resources/Satellite1.png",
	"resources/Asteroid2.png", "resources/Bullet1.png", "resources/EnemyBullet1.png", "resources/heart1.png",
	"resources/LaserGrid.png" };

    struct textureIdentifier {
	sf::Texture texture;
	Objects GameObject;
    };
    vector<textureIdentifier> _textureslList;
};

#endif
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

class GamePresentation
{
public:
    GamePresentation();
    void renderWindow(vector<shared_ptr<MovingObjects> >& gameObjects);
    void UserInputs();
    void UserInputEvents(sf::Keyboard::Key key, bool isPressed);
    void Textures();
    void displayBackground();
    void displaySplashScreen();
    void displayControlScreen();
    void displayGameOverScreen();

    bool LeftKeyPressed = false;
    bool RightKeyPressed = false;
    bool SpacePressed = false;

private:
    sf::RenderWindow _window;
    vector<Resources> _ObjectsTextures;
    sf::Texture _backgroundTexture;
    sf::Sprite _backgroundSprite;

    int Delay = 0;

    vector<string> _paths = { "resources/Spaceship2.png", "resources/Enemy2.png", "resources/Satellite1.png",
	"resources/Asteroid2.png", "resources/Bullet1.png", "resources/EnemyBullet1.png", "resources/heart1.png", "resources/LaserGrid.png" };

    struct textureIdentifier {
	sf::Texture texture;
	Objects GameObject;
    };
    vector<textureIdentifier> _textureslList;
};

#endif
#include "GamePresentation.h"
#include "GamePresentation.h"

using std::string;

sf::Sprite tempSprite;
sf::Texture tempTexture;

GamePresentation::GamePresentation()
    : _window(sf::VideoMode(1000, 800), "Gyruss")
{

    _backgroundTexture.loadFromFile("resources/Nebula.jpg");
    _backgroundTexture.setSmooth(true);
    _backgroundSprite.setTexture(_backgroundTexture);
    drawBackground();

    tempTexture.loadFromFile("resources/Bullet.png");
    tempSprite.setTexture(tempTexture);
    loadTextures();
}

void GamePresentation::drawBackground()
{
    _window.draw(_backgroundSprite);
}

void GamePresentation::renderWindow(vector<shared_ptr<MovingObjects> >& gameObjects)
{
    _window.clear();
    _window.draw(_backgroundSprite);
    for(auto const& gameObject : gameObjects) {
        for(auto const& i : _textureslList) {
            if(i.GameObject == gameObject->GetObject() && gameObject->Status()) {
                sf::Sprite gameObjectSprite;
                gameObjectSprite.setTexture(i.texture);
                gameObjectSprite.setOrigin(i.texture.getSize().x / 2, i.texture.getSize().y / 2);
                gameObjectSprite.setPosition(
                    gameObject->GetPosition().GetCurrentX(), gameObject->GetPosition().GetCurrentY());

                if(gameObject->GetObject() != Objects::Satellites) {
                    gameObjectSprite.setRotation(gameObject->GetPosition().GetAngle() * -0.5);
                }

                gameObjectSprite.setRotation(gameObject->GetPosition().GetAngle() * -0.5);
                _window.draw(gameObjectSprite);
            }
        }
    }
    _window.display();
}

void GamePresentation::processInputEvents()
{
    sf::Event event;
    while(_window.pollEvent(event)) {
        switch(event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        default:
            break;
        }
    }
}

void GamePresentation::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if((key == sf::Keyboard::Right))
        _isRightPressed = isPressed;
    else if((key == sf::Keyboard::Left))
        _isLeftPressed = isPressed;
    if((key == sf::Keyboard::Escape))
        _window.close();
    if(key == sf::Keyboard::Space && isPressed == true)
        if(counter == 0) {
            _isSpacePressed = true;
            counter++;
        }
    if(key == sf::Keyboard::Space && isPressed == false)
        _isSpacePressed = false;
    counter = 0;
}

void GamePresentation::loadTextures()
{
    for(unsigned int i = 0; i != _paths.size(); i++) {
        Resources resource{ static_cast<Objects>(i), _paths.at(i) };
        _ObjectsTextures.push_back(resource);
    }

    for(auto entityTexture : _ObjectsTextures) {
        sf::Texture texture;
        texture.loadFromFile(entityTexture.GetObjectResourcePath());
        texture.setSmooth(true);

        textureIdentifier currentTex;
        currentTex.GameObject = entityTexture.GetGameObjectType();
        currentTex.texture = texture;
        _textureslList.push_back(currentTex);
    }
}

void GamePresentation::displaySplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Display(_window);
}

void GamePresentation::displayControlScreen()
{
    ControlScreen controlscreen;
    controlscreen.Display(_window);
}

void GamePresentation::displayGameOverScreen()
{
    GameOverScreen gameOverScreen;
    gameOverScreen.Display(_window);
}
#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    _SplashTexture.loadFromFile("resources/Universe.jpg");
}

void SplashScreen::Display(sf::RenderWindow& _window)
{
    sf::Sprite Splash;
    Splash.setTexture(_SplashTexture);

    _Font.loadFromFile("Resources/sansation.ttf");
    std::string splashTitle = "Gyruss";
    sf::Text title(splashTitle, _Font);
    title.setCharacterSize(58);
    title.setPosition(_window.getSize().x / 4, _window.getSize().y / 4);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Yellow);

    std::string splashInfo = "Gyruss"
                             "\n "
                             "\n "
                             "\n "
                             "\n \n Press Up key to continue...";

    sf::Text splashText(splashInfo, _Font);
    splashText.setCharacterSize(25);
    splashText.setPosition(_window.getSize().x / 4, _window.getSize().y / 2 - _window.getSize().y / 10);
    splashText.setStyle(sf::Text::Bold);
    splashText.setColor(sf::Color::Yellow);

    _window.draw(Splash);
    _window.draw(splashText);
    _window.draw(title);
    _window.display();

    sf::Event event;
    while(true) {
	while(_window.pollEvent(event)) {
	    if(event.key.code == sf::Keyboard::Up) {
		return;
	    }
	}
    }
}
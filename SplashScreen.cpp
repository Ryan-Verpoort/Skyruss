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
    title.setColor(sf::Color::Black);

    std::string splashInfo = "\n Avoid Asteroids at All Costs!!!!!!!"
                             "\n \n Shoot All Enemies to Win the game"
                             "\n \n Avoid Bullets"
                             "\n \n Shoot All three Satellites to upgrade weapon"
                             "\n \n Lose a life Lose your upgrade"
                             "\n \n \n \n Press Enter key to continue";

    sf::Text splashText(splashInfo, _Font);
    splashText.setCharacterSize(25);
    splashText.setPosition(_window.getSize().x / 4, _window.getSize().y / 2 - _window.getSize().y / 10);
    splashText.setStyle(sf::Text::Bold);
    splashText.setColor(sf::Color::White);

    _window.draw(Splash);
    _window.draw(splashText);
    _window.draw(title);
    _window.display();

    sf::Event event;
    while(true) {
	while(_window.pollEvent(event)) {
	    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		return;
	    }
	}
    }
}
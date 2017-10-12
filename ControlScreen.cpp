#include "ControlScreen.h"

ControlScreen::ControlScreen()
{
    _ControlTexture.loadFromFile("resources/Nebula.jpg");
}

void ControlScreen::Display(sf::RenderWindow& _window)
{
    sf::Sprite Control;
    Control.setTexture(_ControlTexture);

    _Font.loadFromFile("Resources/sansation.ttf");
    std::string splashTitle = "Controls";
    sf::Text title(splashTitle, _Font);
    title.setCharacterSize(58);
    title.setPosition(_window.getSize().x / 4, _window.getSize().y / 4);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Cyan);

    std::string splashControls = "\n Press Space To Shoot"
                                 "\n \n Press Left Arrow Key to move Clockwise"
                                 "\n \n Press Right Arrow Key to move Anti-Clockwise"
                                 "\n \n Press Escape to exit Game "
                                 "\n \n  \n \n Press Enter to begin";

    sf::Text controls(splashControls, _Font);
    controls.setCharacterSize(25);
    controls.setPosition(_window.getSize().x / 4, _window.getSize().y / 2 - _window.getSize().y / 10);
    controls.setStyle(sf::Text::Bold);
    controls.setColor(sf::Color::White);

    _window.draw(Control);
    _window.draw(controls);
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
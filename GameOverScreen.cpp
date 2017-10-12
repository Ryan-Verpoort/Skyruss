#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
    _EndTexture.loadFromFile("resources/Universe.jpg");
}

void GameOverScreen::Display(sf::RenderWindow& renderWindow)
{
    sf::Sprite Final;
    Final.setTexture(_EndTexture);

    _Font.loadFromFile("resources/sansation.ttf");
    std::string Title = "Game Over";
    sf::Text title(Title, _Font);
    title.setCharacterSize(58);
    title.setPosition(renderWindow.getSize().x / 3, renderWindow.getSize().y / 4);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Black);

    std::string gameOverText = "Press Enter to play again"
                               "\n \n  or \n \n or Escape to Exit";

    sf::Text FinalText(gameOverText, _Font);
    FinalText.setCharacterSize(25);
    FinalText.setPosition(renderWindow.getSize().x / 3, renderWindow.getSize().y / 2 - renderWindow.getSize().y / 10);
    FinalText.setStyle(sf::Text::Bold);
    FinalText.setColor(sf::Color::White);

    renderWindow.draw(Final);
    renderWindow.draw(FinalText);
    renderWindow.draw(title);
    renderWindow.display();

    sf::Event event;
    while(true) {
	while(renderWindow.pollEvent(event)) {
	    if(event.key.code == sf::Keyboard::Escape) {
		renderWindow.close();
		return;
	    }
	    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
		return;
	    }
	}
    }
}
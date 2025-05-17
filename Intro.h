#ifndef INTRO_H
#define INTRO_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>
#include "Character.h"

class Intro {
public:
    Intro(sf::RenderWindow& window, const sf::Font& f, const sf::Texture te);
    Character* run(); // Запускает заставку и возвращает выбранного персонажа
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text gameTitle;
    sf::RectangleShape startButton;
    sf::Text startButtonText;
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    std::vector<sf::Text> descriptions;
    bool isMainMenu; // Tracks whether we're in main menu or character selection
    bool initialize(); // Инициализация шрифта, кнопок, текста и фона
};

#endif // INTRO_H
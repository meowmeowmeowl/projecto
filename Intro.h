#ifndef INTRO_H
#define INTRO_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Character.h"

class Intro {
public:
    Intro(sf::RenderWindow& window);
    Character* run(); // Запускает заставку и возвращает выбранного персонажа
private:
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    std::vector<sf::Text> descriptions;
    bool initialize(); // Инициализация шрифта, кнопок и текста
};

#endif // INTRO_H
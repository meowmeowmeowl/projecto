#include "Intro.h"
#include <iostream>

Intro::Intro(sf::RenderWindow& win) : window(win) {
    if (!initialize()) {
        std::cerr << "Failed to initialize intro screen\n";
    }
}

bool Intro::initialize() {
    // Загрузка шрифта
    if (!font.openFromFile("arial.ttf")) {
        return false;
    }

    // Настройка кнопок
    std::vector<std::string> labels = {"Bot Enjoyer", "Chill Guy", "Average"};
    const float buttonWidth = 200.f;
    const float buttonHeight = 50.f;
    const float padding = 20.f;
    const float startX = (800 - (3 * buttonWidth + 2 * padding)) / 2.f;
    const float startY = 300.f;

    for (size_t i = 0; i < 3; ++i) {
        sf::RectangleShape button({buttonWidth, buttonHeight});
        button.setPosition({startX + i * (buttonWidth + padding), startY});
        button.setFillColor(sf::Color::Green);
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        buttons.push_back(button);

        sf::Text text(font);
        // text.setFont(font);
        text.setString(labels[i]);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition({startX + i * (buttonWidth + padding) + 20.f, startY + 15.f});
        buttonTexts.push_back(text);
    }

    // Настройка описаний
    std::vector<std::string> desc = {
        "Bot Enjoyer: Loves coding, strong in bot, weak in talk.",
        "Chill Guy: Relaxed, good at chilling, struggles with bot.",
        "Average: Balanced, no extreme strengths or weaknesses."
    };
    for (size_t i = 0; i < 3; ++i) {
        sf::Text text(font);
        // text.setFont(font);
        text.setString(desc[i]);
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
        text.setPosition({50.f, 400.f + i * 30.f});
        descriptions.push_back(text);
    }

    return true;
}

Character* Intro::run() {
    bool mouseWasPressed = false;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return nullptr;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mouseWasPressed = true;
            }
            if (event->is<sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].getGlobalBounds().contains(mousePos)) {
                        switch (i) {
                        case 0: return new Botenjoyer();
                        case 1: return new Chillguy();
                        case 2: return new Average();
                        }
                    }
                }
                mouseWasPressed = false;
            }
        }

        // Подсветка кнопок
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < buttons.size(); ++i) {
            buttons[i].setFillColor(buttons[i].getGlobalBounds().contains(mousePos) ? sf::Color(100, 200, 100) : sf::Color::Green);
        }

        // Отрисовка
        window.clear(sf::Color(50, 50, 50));
        for (size_t i = 0; i < buttons.size(); ++i) {
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }
        for (const auto& desc : descriptions) {
            window.draw(desc);
        }
        sf::Text title(font);
        // title.setFont(font);
        title.setString("Choose Your Fighter");
        title.setCharacterSize(30);
        title.setFillColor(sf::Color::White);
        title.setPosition({250.f, 50.f});
        window.draw(title);
        window.display();
    }
    return nullptr;
}
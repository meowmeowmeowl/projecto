#include "Intro.h"
#include <iostream>

Intro::Intro(sf::RenderWindow& win, const sf::Font& f, const sf::Texture te) : 
    window(win), font(f), isMainMenu(true), gameTitle(font), startButtonText(font), backgroundTexture(te), backgroundSprite(te)  {
    if (!initialize()) {
        std::cerr << "Failed to initialize intro screen\n";
    }
}
bool Intro::initialize() {
    // Загрузка шрифта
    if (!font.openFromFile("arial.ttf")) {
        return false;
    }

    // Загрузка и настройка фона
    if (!backgroundTexture.loadFromFile("background.png")) {
        std::cerr << "Failed to load background!" << std::endl;
        return false;
    }
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u sizepicture = backgroundTexture.getSize();
    float coefx = static_cast<float>(windowSize.x) / sizepicture.x;
    float coefy = static_cast<float>(windowSize.y) / sizepicture.y;
    backgroundSprite.setScale(sf::Vector2f(coefx, coefy));

    // Настройка главного меню
    gameTitle = sf::Text(font);
    gameTitle.setString("University Life Simulator");
    gameTitle.setCharacterSize(30);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setPosition({150.f, 100.f});

    startButton.setSize({200.f, 50.f});
    startButton.setPosition({300.f, 300.f});
    startButton.setFillColor(sf::Color(253, 246, 171));
    startButton.setOutlineThickness(2.f);
    startButton.setOutlineColor(sf::Color::Black);

    startButtonText = sf::Text(font);
    startButtonText.setString("Start Game");
    startButtonText.setCharacterSize(24);
    startButtonText.setFillColor(sf::Color::Black);
    startButtonText.setPosition({320.f, 315.f});

    // Настройка кнопок выбора персонажа
    std::vector<std::string> labels = {"Bot Enjoyer", "Chill Guy", "Average"};
    const float buttonWidth = 200.f;
    const float buttonHeight = 50.f;
    const float padding = 20.f;
    const float startX = (800 - (3 * buttonWidth + 2 * padding)) / 2.f;
    const float startY = 300.f;

    for (size_t i = 0; i < 3; ++i) {
        sf::RectangleShape button({buttonWidth, buttonHeight});
        button.setPosition({startX + i * (buttonWidth + padding), startY});
        button.setFillColor(sf::Color(253, 246, 171));
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        buttons.push_back(button);

        sf::Text text(font);
        text.setString(labels[i]);
        text.setCharacterSize(24);
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
        text.setString(desc[i]);
        text.setCharacterSize(14);
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
                if (isMainMenu) {
                    if (startButton.getGlobalBounds().contains(mousePos)) {
                        isMainMenu = false; // Переход к выбору персонажа
                    }
                } else {
                    for (size_t i = 0; i < buttons.size(); ++i) {
                        if (buttons[i].getGlobalBounds().contains(mousePos)) {
                            switch (i) {
                            case 0: return new Botenjoyer();
                            case 1: return new Chillguy();
                            case 2: return new Average();
                            }
                        }
                    }
                }
                mouseWasPressed = false;
            }
        }

        // Подсветка кнопок
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (isMainMenu) {
            startButton.setFillColor(startButton.getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
        } else {
            for (size_t i = 0; i < buttons.size(); ++i) {
                buttons[i].setFillColor(buttons[i].getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
            }
        }

        // Отрисовка
        window.clear(sf::Color(50, 50, 50));
        window.draw(backgroundSprite);
        if (isMainMenu) {
            window.draw(gameTitle);
            window.draw(startButton);
            window.draw(startButtonText);
        } else {
            for (size_t i = 0; i < buttons.size(); ++i) {
                window.draw(buttons[i]);
                window.draw(buttonTexts[i]);
            }
            for (const auto& desc : descriptions) {
                window.draw(desc);
            }
            sf::Text title(font);
            title.setString("Choose Your Fighter");
            title.setCharacterSize(30);
            title.setFillColor(sf::Color::White);
            title.setPosition({250.f, 50.f});
            window.draw(title);
        }
        window.display();
    }
    return nullptr;
}
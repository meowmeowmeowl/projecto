#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "changeparams.h"
#include "Action.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Intro.h"

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
    sf::Texture fontexture;
    // Фон
    if (!fontexture.loadFromFile("background.png")) {
        std::cerr << "Failed to load background!" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(fontexture);
    sf::Vector2u sizepicture = fontexture.getSize();
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    // Шкалы для предметов
    const float subWidth = 100.f;
    const float subHeight = 15.f;
    const float paddingsub = 15.f;
    std::vector<int> subnumber = { 1, 2, 3 };
    std::unordered_map<int, std::string> subjects = { {1, "physic"}, {2, "math"}, {3, "proga"} };
    std::vector<sf::Text> subtexts;
    std::vector<sf::RectangleShape> subbackground;
    std::vector<sf::RectangleShape> subprogress;
    const float startYsub = ((subnumber.size() * subHeight + (subnumber.size() - 1) * paddingsub)) / 2.f;
    const float startXsub = 0.f;
    for (size_t i = 0; i < subnumber.size(); ++i) {
        sf::Text text(font);
        text.setString(subjects.at(i + 1));
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        sf::RectangleShape background(sf::Vector2f(subWidth, subHeight));
        background.setFillColor(sf::Color(200, 200, 200));
        background.setOutlineThickness(2.f);
        background.setOutlineColor(sf::Color::Black);
        background.setPosition({ startXsub, i * (subHeight + paddingsub) + startYsub });
        sf::RectangleShape progresssub(sf::Vector2f(0.f, subHeight));
        progresssub.setFillColor(sf::Color(8, 32, 132));
        progresssub.setPosition({ startXsub, i * (subHeight + paddingsub) + startYsub });
        text.setPosition({ background.getPosition().x, background.getPosition().y - background.getSize().y });
        subtexts.push_back(text);
        subbackground.push_back(background);
        subprogress.push_back(progresssub);
    }

    // Кнопка подсчета дней
    const float dayWidth = 60.f;
    const float dayHeight = 20.f;
    sf::RectangleShape daybutton(sf::Vector2f(dayWidth, dayHeight));
    daybutton.setPosition({ 10.f, 5.f });
    daybutton.setFillColor(sf::Color(215, 222, 254));
    daybutton.setOutlineThickness(1.f);
    daybutton.setOutlineColor(sf::Color::Black);
    sf::Text daytext(font);
    daytext.setString("Day 1");
    daytext.setCharacterSize(14);
    daytext.setFillColor(sf::Color::Black);
    daytext.setPosition({ daybutton.getPosition().x + 5.f, daybutton.getPosition().y + 2.f });

    // Кнопка для физры
    const float peWidth = 40.f;
    const float peHeight = 30.f;
    sf::RectangleShape pebutton(sf::Vector2f(peWidth, peHeight));
    pebutton.setPosition({ 750.f, 20.f });
    pebutton.setFillColor(sf::Color(215, 222, 254));
    pebutton.setOutlineThickness(1.f);
    pebutton.setOutlineColor(sf::Color::Black);
    sf::Text peuptext(font);
    peuptext.setString("pe`s count");
    peuptext.setCharacterSize(12);
    peuptext.setFillColor(sf::Color::Black);
    peuptext.setPosition({ pebutton.getPosition().x, pebutton.getPosition().y - pebutton.getSize().y + 5.f });
    sf::Text petext(font);
    petext.setString("0");
    petext.setCharacterSize(14);
    petext.setFillColor(sf::Color::Black);
    petext.setPosition({ pebutton.getPosition().x + pebutton.getSize().y / 2.f, pebutton.getPosition().y + pebutton.getSize().y / 2.f });

    // Шкалы для параметров
    const float barWidth = 150.f;
    const float barHeight = 20.f;
    const float paddingBar = 20.f;
    std::vector<int> barsnumber = { 1, 2, 3, 4, 5 };
    std::unordered_map<int, std::string> conver = { {1, "son"}, {2, "talk"}, {3, "mental"}, {4, "bot"}, {5, "body"} };
    std::vector<sf::Text> bartexts;
    std::vector<sf::RectangleShape> barbackground;
    std::vector<sf::RectangleShape> barprogress;
    const float startYbar = (800 - (barsnumber.size() * barHeight + (barsnumber.size() - 1) * paddingBar)) / 2.f - 150.f;
    const float startXbar = 0.f;
    for (size_t i = 0; i < barsnumber.size(); ++i) {
        sf::Text text(font);
        text.setString(conver.at(i + 1));
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);
        sf::RectangleShape backgroundA(sf::Vector2f(barWidth, barHeight));
        backgroundA.setFillColor(sf::Color(255, 255, 255));
        backgroundA.setOutlineThickness(2.f);
        backgroundA.setOutlineColor(sf::Color::Black);
        backgroundA.setPosition({ startXbar, i * (barHeight + paddingBar) + startYbar });
        sf::RectangleShape progressBar(sf::Vector2f(0.f, barHeight));
        progressBar.setFillColor(sf::Color(8, 32, 132));
        progressBar.setPosition({ startXbar, i * (barHeight + paddingBar) + startYbar });
        text.setPosition({ backgroundA.getPosition().x, backgroundA.getPosition().y - backgroundA.getSize().y + 2.f });
        bartexts.push_back(text);
        barbackground.push_back(backgroundA);
        barprogress.push_back(progressBar);
    }

    // Отображение статов
    std::vector<sf::Text> statTexts;
    const float statX = 650.f;
    const float statY = 100.f;
    const float statPadding = 30.f;
    for (size_t i = 0; i < barsnumber.size(); ++i) {
        sf::Text text(font);
        text.setString(conver.at(i + 1) + ": 0");
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        text.setPosition({ statX, statY + i * statPadding });
        statTexts.push_back(text);
    }

    // Кнопки действий
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::vector<std::string> actionLabels = { "Sleep", "Study", "Care", "Chill", "Active", "PE" };
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;
    const float buttonWidth = 100.f;
    const float buttonHeight = 50.f;
    const float padding = 20.f;
    const float startX = (800 - (numbers.size() * buttonWidth + (numbers.size() - 1) * padding)) / 2.f;
    const float startY = 530.f;
    for (size_t i = 0; i < numbers.size(); ++i) {
        sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
        button.setPosition({ startX + i * (buttonWidth + padding), startY });
        button.setFillColor(sf::Color(253, 246, 171));
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        buttons.push_back(button);

        sf::Text text(font);
        text.setString(actionLabels[i]);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition({ startX + i * (buttonWidth + padding) + 10.f, startY + 15.f });
        buttonTexts.push_back(text);
    }

    // Кнопки выбора предмета для изучения
    bool showStudyMenu = false;
    std::vector<sf::RectangleShape> studyButtons;
    std::vector<sf::Text> studyButtonTexts;
    std::vector<std::string> studyLabels = { "Physics", "Math", "Proga" };
    const float studyButtonWidth = 100.f;
    const float studyButtonHeight = 50.f;
    const float studyStartX = (800 - (3 * studyButtonWidth + 2 * padding)) / 2.f;
    const float studyStartY = 300.f;
    for (size_t i = 0; i < 3; ++i) {
        sf::RectangleShape button(sf::Vector2f(studyButtonWidth, studyButtonHeight));
        button.setPosition({ studyStartX + i * (studyButtonWidth + padding), studyStartY });
        button.setFillColor(sf::Color(253, 246, 171));
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        studyButtons.push_back(button);

        sf::Text text(font);
        text.setString(studyLabels[i]);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition({ studyStartX + i * (studyButtonWidth + padding) + 10.f, studyStartY + 15.f });
        studyButtonTexts.push_back(text);
    }

    // Область для сообщений
    sf::Text statusMessage(font);
    statusMessage.setString("");
    statusMessage.setCharacterSize(16);
    statusMessage.setFillColor(sf::Color::White);
    statusMessage.setPosition({ 200.f, 50.f });
    float messageTimer = 0.f;
    const float messageDuration = 3.f; // Сообщение видно 3 секунды

    // Создаем персонажа
    Intro intro(window, font, fontexture);
    Character* someperson = intro.run();
    if (!someperson) return 0; // Выход, если окно закрыто
    Action activebody(someperson);

    // Главный цикл приложения
    bool mouseWasPressed = false;
    int selectedSubject = 0; // 1: Physics, 2: Math, 3: Proga

    while (window.isOpen()) {
        // Обработка событий
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mouseWasPressed = true;
            }
            if (event->is<sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (showStudyMenu) {
                    for (size_t i = 0; i < studyButtons.size(); ++i) {
                        if (studyButtons[i].getGlobalBounds().contains(mousePos)) {
                            selectedSubject = i + 1; // 1: Physics, 2: Math, 3: Proga
                            showStudyMenu = false;
                            // Выполняем действие изучения
                            if (selectedSubject == 1) {
                                activebody.stud->physic.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[0]);
                            } else if (selectedSubject == 2) {
                                activebody.stud->math.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[1]);
                            } else {
                                activebody.stud->proga.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[2]);
                            }
                            std::vector<int> studyParams;
                            if (dynamic_cast<Botenjoyer*>(activebody.stud)) {
                                studyParams = { -10, 0, 10, 30, -10 };
                            } else if (dynamic_cast<Chillguy*>(activebody.stud)) {
                                studyParams = { -10, 10, 0, -10, 0 };
                            } else {
                                studyParams = { -10, 10, -10, 0, -10 };
                            }
                            activebody.stud->action(studyParams);
                            activebody.pressthebutton();
                            statusMessage.setString("Studied " + studyLabels[i]);
                            messageTimer = messageDuration;
                        }
                    }
                } else {
                    for (size_t i = 0; i < buttons.size(); ++i) {
                        if (buttons[i].getGlobalBounds().contains(mousePos)) {
                            if (numbers[i] == 2) { // Study
                                showStudyMenu = true;
                            } else {
                                processNumber(numbers[i], &activebody);
                                statusMessage.setString("Performed " + actionLabels[i]);
                                messageTimer = messageDuration;
                            }
                        }
                    }
                }
                mouseWasPressed = false;
            }
        }

        // Обновление сообщений
        if (messageTimer > 0) {
            messageTimer -= 0.016f; // Примерно 60 FPS
            if (messageTimer <= 0) {
                statusMessage.setString("");
            }
        }

        // Проверка событий дня
        if (activebody.number_action == 0 && activebody.days > 0) {
            statusMessage.setString("It is a new day");
            messageTimer = messageDuration;
            int count = std::count(activebody.important_days.begin(), activebody.important_days.end(), activebody.days);
            if (count > 0) {
                statusMessage.setString("Deadline uiuiui");
                messageTimer = messageDuration;
            }
        }

        // Подсветка кнопок
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < buttons.size(); ++i) {
            buttons[i].setFillColor(buttons[i].getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
        }
        if (showStudyMenu) {
            for (size_t i = 0; i < studyButtons.size(); ++i) {
                studyButtons[i].setFillColor(studyButtons[i].getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
            }
        }

        // Обновление UI
        daytext.setString("Day: " + std::to_string(activebody.days + 1));
        petext.setString(std::to_string(activebody.stud->pe.value));
        for (size_t i = 0; i < barsnumber.size(); ++i) {
            int num = activebody.stud->stats.at(conver.at(i + 1));
            barprogress[i].setSize(sf::Vector2f(barWidth * (num / 100.0f), barHeight));
            statTexts[i].setString(conver.at(i + 1) + ": " + std::to_string(num));
        }
        subprogress[0].setSize(sf::Vector2f(subWidth * (activebody.stud->physic.value / 100.0f), subHeight));
        subprogress[1].setSize(sf::Vector2f(subWidth * (activebody.stud->math.value / 100.0f), subHeight));
        subprogress[2].setSize(sf::Vector2f(subWidth * (activebody.stud->proga.value / 100.0f), subHeight));

        // Отрисовка
        sf::Vector2u windowSize = window.getSize();
        float coefx = static_cast<float>(windowSize.x) / sizepicture.x;
        float coefy = static_cast<float>(windowSize.y) / sizepicture.y;
        backgroundSprite.setScale(sf::Vector2f(coefx, coefy));
        window.clear(sf::Color(50, 50, 50));
        window.draw(backgroundSprite);
        window.draw(pebutton);
        window.draw(petext);
        window.draw(peuptext);
        window.draw(daybutton);
        window.draw(daytext);
        for (size_t i = 0; i < subnumber.size(); ++i) {
            window.draw(subbackground[i]);
            window.draw(subprogress[i]);
            window.draw(subtexts[i]);
        }
        for (size_t i = 0; i < barsnumber.size(); ++i) {
            window.draw(barbackground[i]);
            window.draw(bartexts[i]);
            window.draw(barprogress[i]);
        }
        for (size_t i = 0; i < buttons.size(); ++i) {
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }
        for (const auto& statText : statTexts) {
            window.draw(statText);
        }
        if (showStudyMenu) {
            for (size_t i = 0; i < studyButtons.size(); ++i) {
                window.draw(studyButtons[i]);
                window.draw(studyButtonTexts[i]);
            }
        }
        if (messageTimer > 0) {
            window.draw(statusMessage);
        }
        window.display();
    }

    delete someperson;
    return 0;
}
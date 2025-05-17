#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "changeparams.h"
#include "Action.h"
#include "youdead.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Intro.h"

std::string reason ="no";
class DeadWindow {
public:
    void run(std::string reas) {
        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
        sf::Texture fontexture;
        // Фон
        if (!fontexture.loadFromFile("C:/Users/Мария/source/repos/with_sfml/fon.jpg")) {
            std::cerr << "Failed to load background!" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(fontexture);
        sf::Vector2u sizepicture = fontexture.getSize();
        sf::Font font;
        if (!font.openFromFile("C:/Users/Мария/source/repos/with_sfml/arialmt.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }
        sf::Vector2u windowSize = window.getSize();
        float coefx = static_cast<float>(windowSize.x) / sizepicture.x;
        float coefy = static_cast<float>(windowSize.y) / sizepicture.y;
        backgroundSprite.setScale(sf::Vector2f(coefx, coefy));

        sf::Text acceptionText = sf::Text(font);
        std::string intext = "O no you are dead";
        youdead(reas, intext);
        acceptionText.setString(intext);//
        acceptionText.setCharacterSize(24);
        acceptionText.setFillColor(sf::Color::Black);
        acceptionText.setPosition({ 320.f, 235.f });
        sf::RectangleShape accept;
        accept.setSize({ 350.f, 60.f });
        accept.setPosition({ 300.f, 200.f });
        accept.setFillColor(sf::Color::White);
        accept.setOutlineThickness(2.f);
        accept.setOutlineColor(sf::Color::Black);
        bool mouseWasPressed = false;
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                    return;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    mouseWasPressed = true;
                }
                if (event->is<sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    window.close();
                    return;
                    mouseWasPressed = false;
                }
            }
            // Отрисовка
            window.clear(sf::Color(50, 50, 50));
            window.draw(backgroundSprite);
            window.draw(accept);
            window.draw(acceptionText);
            window.display();
        }
    }
};
class MainWindow {
public:
    void run() {
        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
        sf::Texture fontexture;
        // Фон
        if (!fontexture.loadFromFile("C:/Users/Мария/source/repos/with_sfml/fon.jpg")) {
            std::cerr << "Failed to load background!" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(fontexture);
        sf::Vector2u sizepicture = fontexture.getSize();
        sf::Font font;
        if (!font.openFromFile("C:/Users/Мария/source/repos/with_sfml/arialmt.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
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

        // Текстовое поле для ввода
        bool showTextField = false;
        std::string inputText = "";
        sf::RectangleShape textField(sf::Vector2f(100.f, 30.f));
        textField.setPosition({ 350.f, 350.f });
        textField.setFillColor(sf::Color(255, 255, 255));
        textField.setOutlineThickness(2.f);
        textField.setOutlineColor(sf::Color::Black);
        sf::Text inputTextDisplay(font);
        inputTextDisplay.setString("");
        inputTextDisplay.setCharacterSize(20);
        inputTextDisplay.setFillColor(sf::Color::Black);
        inputTextDisplay.setPosition({ 360.f, 355.f });
        sf::Text questionText(font);
        questionText.setString("");
        questionText.setCharacterSize(16);
        questionText.setFillColor(sf::Color::White);
        questionText.setPosition({ 200.f, 300.f });

        // Область для сообщений
        sf::Text statusMessage(font);
        statusMessage.setString("");
        statusMessage.setCharacterSize(16);
        statusMessage.setFillColor(sf::Color::Black);
        statusMessage.setPosition({ 200.f, 50.f });
        float messageTimer = 0.f;
        const float messageDuration = 3.f;

        // Создаем персонажа
        Intro intro(window, font, fontexture);
        Character* someperson = intro.run();
        // if (!someperson) return 0;
        Action activebody(someperson);

        // Состояние для вопросов
        enum class InputState { None, Study, Achievement };
        InputState inputState = InputState::None;
        std::string achievementSubject = "";
        bool mouseWasPressed = false;
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                if (showTextField && event->is<sf::Event::TextEntered>()) {
                    const auto* textentered = event->getIf<sf::Event::TextEntered>();
                    if (textentered->unicode >= '0' && textentered->unicode <= '3') {
                        inputText = static_cast<char>(textentered->unicode);
                        inputTextDisplay.setString(inputText);
                    }
                    else if (textentered->unicode == 8 && !inputText.empty()) { // Backspace
                        inputText.clear();
                        inputTextDisplay.setString("");
                    }
                }
                if (showTextField && event->is<sf::Event::KeyPressed>()) {
                    const auto* keypressed = event->getIf<sf::Event::KeyPressed>();
                    if (keypressed->code == sf::Keyboard::Key::Enter && !inputText.empty()) {
                        int input = std::stoi(inputText);
                        if (inputState == InputState::Study) {
                            if (input >= 1 && input <= 3) {
                                if (input == 1) {
                                    activebody.stud->physic.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[0]);
                                }
                                else if (input == 2) {
                                    activebody.stud->math.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[1]);
                                }
                                else {
                                    activebody.stud->proga.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[2]);
                                }
                                std::vector<int> studyParams;
                                if (dynamic_cast<Botenjoyer*>(activebody.stud)) {
                                    studyParams = { -10, 0, 10, 30, -10 };
                                }
                                else if (dynamic_cast<Chillguy*>(activebody.stud)) {
                                    studyParams = { -10, 10, 0, -10, 0 };
                                }
                                else {
                                    studyParams = { -10, 10, -10, 0, -10 };
                                }
                                activebody.stud->action(studyParams);
                                activebody.pressthebutton();
                                statusMessage.setString("Studied " + subjects[input]);
                                messageTimer = messageDuration;
                            }
                        }
                        else if (inputState == InputState::Achievement) {
                            if (input == 1) {
                                if (achievementSubject == "physic") {
                                    activebody.stud->achieve.numbers[0] = 1;
                                    statusMessage.setString("Improved physics");
                                }
                                else if (achievementSubject == "math") {
                                    activebody.stud->achieve.numbers[1] = 1;
                                    statusMessage.setString("Improved math");
                                }
                                else if (achievementSubject == "proga") {
                                    activebody.stud->achieve.numbers[2] = 1;
                                    statusMessage.setString("Improved programming");
                                }
                            }
                            else {
                                statusMessage.setString("Skipped improvement");
                            }
                            messageTimer = messageDuration;
                        }
                        showTextField = false;
                        inputText.clear();
                        inputTextDisplay.setString("");
                        inputState = InputState::None;
                    }
                }
                if (event->is<sf::Event::MouseButtonPressed>() && event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
                    mouseWasPressed = true;
                }
                if (event->is<sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                    const auto* mousereleased = event->getIf<sf::Event::MouseButtonReleased>();
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(mousereleased->position.x, mousereleased->position.y));
                    if (!showTextField) {
                        for (size_t i = 0; i < buttons.size(); ++i) {
                            if (buttons[i].getGlobalBounds().contains(mousePos)) {
                                if (numbers[i] == 2) { // Study
                                    showTextField = true;
                                    inputState = InputState::Study;
                                    questionText.setString("Choose subject (1: Physics, 2: Math, 3: Proga)");
                                }
                                else {
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

            // Проверка событий дня и достижений
            if (activebody.number_action == 0 && activebody.days > 0) {
                statusMessage.setString("It is a new day");
                messageTimer = messageDuration;
                int count = std::count(activebody.important_days.begin(), activebody.important_days.end(), activebody.days);
                int cou = std::count(activebody.achievement_days.begin(), activebody.achievement_days.end(), activebody.days);
                if (count > 0) {
                    statusMessage.setString("Deadline uiuiui");
                    messageTimer = messageDuration;
                }
                if (cou > 0 && !showTextField) {
                    std::unordered_map<std::string, int> priv;
                    priv["physic"] = activebody.stud->achieve.numbers[0];
                    priv["math"] = activebody.stud->achieve.numbers[1];
                    priv["proga"] = activebody.stud->achieve.numbers[2];
                    std::vector<std::string> arezero;
                    for (const auto& pair : priv) {
                        if (pair.second == 0) {
                            arezero.push_back(pair.first);
                        }
                    }
                    if (!arezero.empty()) {
                        int randomIndex = std::rand() % arezero.size();
                        achievementSubject = arezero[randomIndex];
                        showTextField = true;
                        inputState = InputState::Achievement;
                        questionText.setString("Improve " + achievementSubject + "? (1: Yes, 0: No)");
                    }
                }
            }

            // Подсветка кнопок
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            for (size_t i = 0; i < buttons.size(); ++i) {
                buttons[i].setFillColor(buttons[i].getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
            }

            // Обновление UI проверка на жизнь
            daytext.setString("Day: " + std::to_string(activebody.days + 1));
            petext.setString(std::to_string(activebody.stud->pe.value));
            if (activebody.alive == 0) {
                reason = activebody.reason;
                //window.clear();
                return;
            }
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
            if (showTextField) {
                window.draw(questionText);
                window.draw(textField);
                window.draw(inputTextDisplay);
            }
            if (messageTimer > 0) {
                window.draw(statusMessage);
            }
            window.display();
        }
    }
};
int main() {
    MainWindow mainwindow;
    mainwindow.run();
    DeadWindow deadwindow;
    deadwindow.run(reason);
    return 0;
}
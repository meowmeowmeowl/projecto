#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
bool processNumber(int number, sf::Text& pressedNumberText, std::vector<sf::RectangleShape>& newButtons, std::vector<sf::Text>& newButtonTexts, sf::Font& font) {
    std::cout << "Pressed button with number " << number << std::endl;
    pressedNumberText.setString("Pressed button: " + std::to_string(number));

    // Создаем новые кнопки
    const float newButtonWidth = 100.f;
    const float newButtonHeight = 50.f;
    const float newPadding = 20.f;
    const float newStartX = (800 - (3 * newButtonWidth + 2 * newPadding)) / 2.f;
    const float newStartY = 300.f; // Позиция ниже оригинальных кнопок

    for (int i = 0; i < 3; ++i) {
        // Создаем прямоугольник новой кнопки
        sf::RectangleShape button({ sf::Vector2f(newButtonWidth, newButtonHeight) });
        button.setPosition({ newStartX + i * (newButtonWidth + newPadding), newStartY });
        button.setFillColor(sf::Color::Blue);
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        newButtons.push_back(button);

        // Создаем текст для новой кнопки
        sf::Text text(font);
        text.setFont(font);
        text.setString(std::to_string(i + 1));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        // Центрируем текст
        sf::FloatRect textRect = text.getLocalBounds();
        text.setPosition({ newStartX + i * (newButtonWidth + newPadding) + newButtonWidth / 2.0f ,
                           newStartY + newButtonHeight / 2.0f });

        newButtonTexts.push_back(text);
    }

    return true; // Указываем, что кнопка была нажата


}
// Функция для обработки нажатий на новые кнопки
void processNewButtonClick(int number, sf::Text& pressedNumberText, std::vector<sf::RectangleShape>& newButtons, std::vector<sf::Text>& newButtonTexts) {
    std::cout << "New button pressed with number " << number << std::endl;
    pressedNumberText.setString("New button pressed: " + std::to_string(number));

    // Очищаем новые кнопки и тексты
    newButtons.clear();
    newButtonTexts.clear();

    std::cout << number;
}
int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Кнопки с числами");
    sf::Font font;
    if (!font.openFromFile("C:/Users/Masha/source/repos/sfmllll/Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }
    // Загружаем шрифт


    // Числа для наших кнопок
    std::vector<int> numbers = { 1, 2, 3 };

    // Создаем кнопки
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;

    // Параметры кнопок
    const float buttonWidth = 100.f;
    const float buttonHeight = 50.f;
    const float padding = 20.f;
    const float startX = (800 - (numbers.size() * buttonWidth + (numbers.size() - 1) * padding)) / 2.f;
    const float startY = 200.f;
    sf::Text pressedNumberText(font);
    pressedNumberText.setFont(font);
    pressedNumberText.setCharacterSize(30);
    pressedNumberText.setFillColor(sf::Color::White);
    pressedNumberText.setString("");


    for (size_t i = 0; i < numbers.size(); ++i) {
        // Создаем прямоугольник кнопки
        sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
        button.setPosition({ startX + i * (buttonWidth + padding), startY });
        button.setFillColor(sf::Color::Green);
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        buttons.push_back(button);

        // Создаем текст для кнопки
        sf::Text text(font);
        text.setString(std::to_string(numbers[i]));
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);



        //sf::RectangleShape rectangle({ 120.f, 50.f });
        /*text.setOrigin( { startX + i * (buttonWidth + padding) + buttonWidth/2.f, startY + buttonHeight/2.f});
        */
        if (i == 0) {
            text.setPosition({ startX + i * (buttonWidth + padding) + buttonWidth / 2.f
  ,
     startY + buttonHeight / 4.f }

            );
            buttonTexts.push_back(text);

        }
        else {
            text.setPosition({ startX + buttonWidth / 2.f + i * (buttonWidth + padding)
          ,
             startY + buttonHeight / 4.f }

            );
            buttonTexts.push_back(text);
        }



    }

    // Главный цикл приложения
    bool mouseWasPressed = false;
    // Создаем статические переменные для новых кнопок
    std::vector<sf::RectangleShape> newButtons;
    std::vector<sf::Text> newButtonTexts;
    bool oldButtonsEnabled = true;
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mouseWasPressed = true;
            }
            if (event->is < sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                // Получаем позицию мыши
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePos = window.mapPixelToCoords(
                    localPosition);

                // Проверяем, какая кнопка была нажата

                if (oldButtonsEnabled) {
                    for (size_t i = 0; i < buttons.size(); ++i) {
                        if (buttons[i].getGlobalBounds().contains(mousePos)) {
                            processNumber(numbers[i], pressedNumberText, newButtons, newButtonTexts, font);
                            oldButtonsEnabled = false; // Делаем старые кнопки недоступными
                        }
                    }
                }
                //for (size_t i = 0; i < buttons.size(); ++i) {
                //    if (buttons[i].getGlobalBounds().contains(mousePos)) {
                //        processNumber(numbers[i], pressedNumberText, newButtons, newButtonTexts, font); // Вызываем функцию с числом

                //    }
                //}
                // Проверяем нажатие на новые кнопки
                for (size_t i = 0; i < newButtons.size(); ++i) {
                    if (newButtons[i].getGlobalBounds().contains(mousePos)) {
                        processNewButtonClick(i + 1, pressedNumberText, newButtons, newButtonTexts);
                        oldButtonsEnabled = true; // Можно снова сделать старые кнопки доступными при нажатии новой
                    }
                }
            }




        }

        // Обработка нажатий на кнопки
// Изменяем цвет кнопок при наведении
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < buttons.size(); ++i) {
            if (buttons[i].getGlobalBounds().contains(mousePos)) {
                buttons[i].setFillColor(sf::Color(100, 200, 100)); // Светло-зеленый
            }
            else {
                buttons[i].setFillColor(sf::Color::Green); // Обычный зеленый
            }
        }
        
        // Подсветка новых кнопок при наведении мыши
        sf::Vector2f mousePos1 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < newButtons.size(); ++i) {
            if (newButtons[i].getGlobalBounds().contains(mousePos1)) {
                newButtons[i].setFillColor(sf::Color::Cyan); // Подсветка
            }
            else {
                newButtons[i].setFillColor(sf::Color::Blue); // Цвет по умолчанию
            }
        }
        
        // Отрисовка
        window.clear(sf::Color(50, 50, 50)); // Темный фон
        // Рисуем первоначальные кнопки независимо от их состояния
        for (const auto& button : buttons) {
            window.draw(button);
        }

        // Рисуем текст на кнопках
        for (const auto& text : buttonTexts) {
            window.draw(text);
        }
        //// Рисуем кнопки и текст
        //for (size_t i = 0; i < buttons.size(); ++i) {
        //    window.draw(buttons[i]);
        //    window.draw(buttonTexts[i]);
        //}

        window.draw(pressedNumberText);

        //// Рисуем новые кнопки и их текст только если они были созданы
        for (auto& newButton : newButtons) {
            window.draw(newButton);
        }
        for (auto& newButtonText : newButtonTexts)
        {
            window.draw(newButtonText);
        }
        //for (i = 0;i < 3, auto & newButtonText : newButtonTexts)







        window.display();
    }
    return 0;
}

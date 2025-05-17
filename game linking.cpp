
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>

bool processNumber(int number, sf::Text& pressedNumberText, std::vector<sf::RectangleShape>& newButtons, std::vector<sf::Text>& newButtonTexts, sf::Font& font) {
    std::cout << "Pressed button with number " << number << std::endl;
    pressedNumberText.setString("Pressed button: " + std::to_string(number));

    // ������� ����� ������
    const float newButtonWidth = 100.f;
    const float newButtonHeight = 50.f;
    const float newPadding = 20.f;
    const float newStartX = (800 - (3 * newButtonWidth + 2 * newPadding)) / 2.f;
    const float newStartY = 300.f; // ������� ���� ������������ ������

    for (int i = 0; i < 3; ++i) {
        // ������� ������������� ����� ������
        sf::RectangleShape button({ sf::Vector2f(newButtonWidth, newButtonHeight) });
        button.setPosition({ newStartX + i * (newButtonWidth + newPadding), newStartY });
        button.setFillColor(sf::Color::Blue);
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        newButtons.push_back(button);

        // ������� ����� ��� ����� ������
        sf::Text text(font);
        text.setFont(font);
        text.setString(std::to_string(i + 1));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        // ���������� �����
        sf::FloatRect textRect = text.getLocalBounds();
        text.setPosition({ newStartX + i * (newButtonWidth + newPadding) + newButtonWidth / 2.0f ,
                           newStartY + newButtonHeight / 2.0f });

        newButtonTexts.push_back(text);
    }

    return true;

}
// ������� ��� ��������� ������� �� ����� ������
void processNewButtonClick(int number, sf::Text& pressedNumberText, std::vector<sf::RectangleShape>& newButtons, std::vector<sf::Text>& newButtonTexts) {
    std::cout << "New button pressed with number " << number << std::endl;
    pressedNumberText.setString("New button pressed: " + std::to_string(number));

    newButtons.clear();
    newButtonTexts.clear();

    std::cout << number;
}
int main() {
    // ������� ����
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
   
    sf::Font font;
    if (!font.openFromFile("C:/Users/Masha/source/repos/sfmllll/Arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }



    // ����� ��� ����� ������
    std::vector<int> numbers = { 1, 2, 3 };

    // ������� ������
    std::vector<sf::RectangleShape> buttons;
    std::vector<sf::Text> buttonTexts;

    // ��������� ������
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
        // ������� ������������� ������
        sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
        button.setPosition({ startX + i * (buttonWidth + padding), startY });
        button.setFillColor(sf::Color::Green);
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Black);
        buttons.push_back(button);

        // ������� ����� ��� ������
        sf::Text text(font);
        text.setString(std::to_string(numbers[i]));
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);





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

    bool mouseWasPressed = false;

    std::vector<sf::RectangleShape> newButtons;
    std::vector<sf::Text> newButtonTexts;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mouseWasPressed = true;
            }
            if (event->is < sf::Event::MouseButtonReleased>() && mouseWasPressed) {
                // �������� ������� ����
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                sf::Vector2f mousePos = window.mapPixelToCoords(
                    localPosition);

                // ���������, ����� ������ ���� ������

                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].getGlobalBounds().contains(mousePos)) {
                        processNumber(numbers[i], pressedNumberText, newButtons, newButtonTexts, font); // �������� ������� � ������

                    }
                }

                // ��������� ������� �� ����� ������
                for (size_t i = 0; i < newButtons.size(); ++i) {
                    if (newButtons[i].getGlobalBounds().contains(mousePos)) {
                        processNewButtonClick(i + 1, pressedNumberText, newButtons, newButtonTexts); // �������� ����� ����� ������
                    }

                }
            }




        }

        // �������� ���� ������ ��� ���������
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < buttons.size(); ++i) {
            if (buttons[i].getGlobalBounds().contains(mousePos)) {
                buttons[i].setFillColor(sf::Color(100, 200, 100)); // ������-�������
            }
            else {
                buttons[i].setFillColor(sf::Color::Green); // ������� �������
            }
        }

        // ���������
        window.clear(sf::Color(50, 50, 50)); // ������ ���

        for (size_t i = 0; i < buttons.size(); ++i) {
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }

        window.draw(pressedNumberText);

        for (auto& newButton : newButtons) {
            window.draw(newButton);
        }
        for (auto& newButtonText : newButtonTexts)
        {
            window.draw(newButtonText);
        }








        window.display();
    }
    return 0;
}






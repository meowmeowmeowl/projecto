#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include "Action.h"
#include <cstdlib>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
void sleep(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "sleep" << std::endl;
	student->actionsleep();
	meow->pressthebutton();
	student->showstats();

}
void bot(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "study" << std::endl;
	student->actionstudy();
	meow->pressthebutton();
	student->showstats();
	student->physic.showprogress();
	student->math.showprogress();
	student->proga.showprogress();
	

}
void care(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "care" << std::endl;
	student->actioncare();
	meow->pressthebutton();
	student->showstats();
}
	
void talk(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "talk" << std::endl;
	student->actionactive();
	meow->pressthebutton();
	student->showstats();
}
void chill(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "chill" << std::endl;
	student->actionchill();
	meow->pressthebutton();
	student->showstats();
}
void pe(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	std::cout << "pe" << std::endl;
	student->actionpe();
	meow->pressthebutton();
	student->showstats();
	student->pe.showprogress();
}

void processNumber(int number, Action* meow) {
	if (number == 1) {
		sleep(meow);
	}
	else if (number == 2) {
		bot(meow);
	}
	else if (number == 3) {
		care(meow);
	}
	else if (number == 4) {
		talk(meow);
	}
	else if (number == 5) {
		chill(meow);
	}
	else {
		pe(meow);
	}
}
int main() {
		// Создаем окно
		sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
		//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Кнопки с числами");
		sf::Font font;
		if (!font.openFromFile("C:/Users/Мария/source/repos/with_sfml/arialmt.ttf")) { //помните что путь до файла свой везде
			std::cerr << "Failed to load font!" << std::endl;
			return -1;
		}
		// Загружаем шрифт


		// Числа для наших кнопок
		std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
		// Создаем кнопки
		std::vector<sf::RectangleShape> buttons;
		std::vector<sf::Text> buttonTexts;

		// Параметры кнопок
		const float buttonWidth = 100.f;
		const float buttonHeight = 50.f;
		const float padding = 20.f;
		const float startX = (800 - (numbers.size() * buttonWidth + (numbers.size() - 1) * padding)) / 2.f;
		const float startY = 200.f;

		// Создаем прямоугольники и текст для кнопок
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
		//создаем персонажа
		Character* someperson;
		std::cout << "Choose your fighter:" << "\n" << "press 1 if you like bot" << "\n" << "press 2 if you are just a chill guy" << "\n" << "press 3 if you are average" << std::endl;
		int player;
		std::cin >> player;
		if (player == 1) {
			someperson = new Botenjoyer;
		}
		else if (player == 2) {
			someperson = new Chillguy;
		}
		else {
			someperson = new Average;
		}
		someperson->showstats();
		Action activebody(someperson);

		// Главный цикл приложения
		bool mouseWasPressed = false;

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

					for (size_t i = 0; i < buttons.size(); ++i) {
						if (buttons[i].getGlobalBounds().contains(mousePos)) {
							processNumber(numbers[i], &activebody); // Вызываем функцию с числом

						}
					}
					// left mouse button is pressed: shoot
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

			// Отрисовка
			window.clear(sf::Color(50, 50, 50)); // Темный фон

			// Рисуем кнопки и текст
			for (size_t i = 0; i < buttons.size(); ++i) {
				window.draw(buttons[i]);
				window.draw(buttonTexts[i]);
			}

			window.display();
		}


	return 0;
}

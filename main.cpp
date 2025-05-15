#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 
//#include "changeparams.h"
#include "Action.h"
#include <cstdlib>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
const std::unordered_map<int, std::string > conver = {
		{0, "son"},
		{1, "talk"},
		{2, "mental"},
		{3, "bot"},
		{4, "body"}
};
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


void processNumber(int number, Action* meow, std::vector<sf::RectangleShape> barprogress) {
	Character* student = meow->stud;
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
		//ДЕЛАЕМ ШКАЛЫ ДЛЯ БОТА ПРЕДМЕТОВ
		const float subWidth = 100.f;
		const float subHeight = 30.f;
		const float paddingsub = 20.f;
		std::vector<int> subnumber = { 1,2,3};
		std::vector<sf::RectangleShape> subbackground;
		std::vector<sf::RectangleShape> subprogress;
		const float startYsub = ((subnumber.size() * subHeight + (subnumber.size() - 1) * paddingsub)) / 2.f;
		const float startXsub = 0.f;
		for (size_t i = 0; i < subnumber.size(); ++i) {
			sf::RectangleShape background(sf::Vector2f(subWidth, subHeight));
			background.setFillColor(sf::Color(255, 200, 0));
			background.setPosition({ startXsub,  i * (subHeight + paddingsub) + startYsub }); // Позиция шкалы
			sf::RectangleShape progresssub(sf::Vector2f(0.f, subHeight)); // Начальная ширина 0
			progresssub.setFillColor(sf::Color(0, 255, 0)); // Зеленый цвет
			progresssub.setPosition({ startXsub, i * (subHeight + paddingsub) + startYsub });
			subbackground.push_back(background);
			subprogress.push_back(progresssub);
		}

		//ДЕЛАЕМ ШКАЛЫ ДЛЯ ПАРАМЕТРОВ
		
		const float barWidth = 200.f;
		const float barHeight = 30.f;
		const float paddingBar = 20.f;
		std::vector<int> barsnumber = { 1,2,3,4,5 };
		std::vector<sf::RectangleShape> barbackground;
		std::vector<sf::RectangleShape> barprogress;
		const float startYbar = (800 - (barsnumber.size() * barHeight + (barsnumber.size() - 1) * paddingBar)) / 2.f;
		const float startXbar = 0.f;
		for (size_t i = 0; i < barsnumber.size(); ++i) {
			sf::RectangleShape background(sf::Vector2f(barWidth, barHeight));
			background.setFillColor(sf::Color(255, 255, 255)); 
			background.setPosition({ startXbar,  i * (barHeight + paddingBar)+  startYbar }); // Позиция шкалы
			sf::RectangleShape progressBar(sf::Vector2f(0.f, barHeight)); // Начальная ширина 0
			progressBar.setFillColor(sf::Color(0, 255, 0)); // Зеленый цвет
			progressBar.setPosition({ startXbar , i * (barHeight + paddingBar) + startYbar });
			barbackground.push_back(background);
			barprogress.push_back(progressBar
);

		}
		//ДЕЛАЕМ КНОПОЧКИ

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
							processNumber(numbers[i], &activebody, barprogress); // Вызываем функцию с числом
							for (int i = 0; i < 5; ++i) {
								int num = activebody.stud->stats.at(conver.at(i));
								barprogress[i].setSize(sf::Vector2f(barWidth * (num / 100.0f), barHeight)); // Пример  прогресса
								window.draw(barprogress[i]);

							}
							if (numbers[i] == 2) {
								int physic = activebody.stud->physic.value;
								subprogress[0].setSize(sf::Vector2f(subWidth * (physic / 100.0f), subHeight)); // Пример  прогресса
								window.draw(subprogress[0]);
								int math = activebody.stud->math.value;
								subprogress[1].setSize(sf::Vector2f(subWidth * (math / 100.0f), subHeight)); // Пример  прогресса
								window.draw(subprogress[1]);
								int proga = activebody.stud->proga.value;
								subprogress[2].setSize(sf::Vector2f(subWidth * (proga/ 100.0f), subHeight)); // Пример  прогресса
								window.draw(subprogress[2]);
							}
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
			//Рисуем шкалы предметов
			for (size_t i = 0; i < subnumber.size(); ++i) {
				window.draw(subbackground[i]);
				window.draw(subprogress[i]);
			}
			// Рисуем шкалы параметров
			for (size_t i = 0; i < barsnumber.size(); ++i) {
				window.draw(barbackground[i]);
				for (int i = 0; i < 5; ++i) {
					int num = activebody.stud->stats.at(conver.at(i));
					barprogress[i].setSize(sf::Vector2f(barWidth * (num / 100.0f), barHeight)); // Пример  прогресса
					window.draw(barprogress[i]);

				}

			}
			// Рисуем кнопки и текст
			for (size_t i = 0; i < buttons.size(); ++i) {
				window.draw(buttons[i]);
				window.draw(buttonTexts[i]);
			}

			window.display();
		}


	return 0;
}

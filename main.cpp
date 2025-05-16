#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include "changeparams.h"
#include "Action.h"
#include <cstdlib>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Intro.h"


int main() {
		// Создаем окно
		sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");
		sf::Texture fontexture;
		//фон
		if (!fontexture.loadFromFile("background.png")) {
			std::cerr << "Failed to load background!" << std::endl;
			return -1;
		}
		sf::Sprite backgroundSprite(fontexture);
		sf::Vector2u sizepicture = fontexture.getSize();
		//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Кнопки с числами");
		sf::Font font;
		if (!font.openFromFile("arial.ttf")) { //помните что путь до файла свой везде
			std::cerr << "Failed to load font!" << std::endl;
			return -1;
		}
		//ДЕЛАЕМ ШКАЛЫ ДЛЯ БОТА ПРЕДМЕТОВ

		const float subWidth = 100.f;
		const float subHeight = 15.f;
		const float paddingsub = 15.f;
		std::vector<int> subnumber = { 1,2,3};
		std::unordered_map<int, std::string> subjects = { {1, "physic"}, {2, "math"} , {3, "proga"} };
		std::vector<sf::Text> subtexts;
		std::vector<sf::RectangleShape> subbackground;
		std::vector<sf::RectangleShape> subprogress;
		const float startYsub = ((subnumber.size() * subHeight + (subnumber.size() - 1) * paddingsub)) / 2.f ;
		const float startXsub = 0.f;
		for (size_t i = 0; i < subnumber.size(); ++i) {
			sf::Text text(font);
			text.setString(subjects.at(i+ 1));
			text.setFont(font);
			text.setCharacterSize(14);
			text.setFillColor(sf::Color::Black);
			sf::RectangleShape background(sf::Vector2f(subWidth, subHeight));
			background.setFillColor(sf::Color(200, 200, 200));
			background.setOutlineThickness(2.f);
			background.setOutlineColor(sf::Color::Black);
			background.setPosition({ startXsub,  i * (subHeight + paddingsub) + startYsub }); // Позиция шкалы
			sf::RectangleShape progresssub(sf::Vector2f(0.f, subHeight)); // Начальная ширина 0
			progresssub.setFillColor(sf::Color(8,32,132)); 
			progresssub.setPosition({ startXsub, i * (subHeight + paddingsub) + startYsub });
			text.setPosition({ background.getPosition().x,background.getPosition().y - background.getSize().y});
			subtexts.push_back(text);
			subbackground.push_back(background);
			subprogress.push_back(progresssub);

		}
		//ОСОБАЯ КНОПКА ПОДСЧЕТА ДНЕЙ
		const float dayWidth = 60.f;
		const float dayHeight = 20.f;
		sf::RectangleShape daybutton(sf::Vector2f(dayWidth, dayHeight));
		daybutton.setPosition({ 10.f, 5.f });
		daybutton.setFillColor(sf::Color(215, 222, 254));
		daybutton.setOutlineThickness(1.f);
		daybutton.setOutlineColor(sf::Color::Black);
		sf::Text daytext(font);
		daytext.setString("Day 1: ");
		daytext.setCharacterSize(14);
		daytext.setFillColor(sf::Color::Black);
		daytext.setPosition({ daybutton.getPosition().x  - 6.f + daybutton.getSize().y / 2.f,daybutton.getPosition().y + daybutton.getSize().y / 2.f  - 6.f});

		//ОСОБАЯ КНОПКА ДЛЯ ФИЗРЫ
		const float peWidth = 40.f;
		const float peHeight = 30.f;
		sf::RectangleShape pebutton(sf::Vector2f(peWidth, peHeight));
		pebutton.setPosition({750.f, 20.f });
		pebutton.setFillColor(sf::Color(215,222,254));
		pebutton.setOutlineThickness(1.f);
		pebutton.setOutlineColor(sf::Color::Black);
		sf::Text peuptext(font);
		peuptext.setString("pe`s count");
		peuptext.setFont(font);
		peuptext.setCharacterSize(12);
		peuptext.setFillColor(sf::Color::Black);
		peuptext.setPosition({ pebutton.getPosition().x,pebutton.getPosition().y - pebutton.getSize().y+5.f});
		sf::Text petext(font);
		petext.setString("0");
		petext.setFont(font);
		petext.setCharacterSize(14);
		petext.setFillColor(sf::Color::Black);
		petext.setPosition({ pebutton.getPosition().x+ pebutton.getSize().y/2.f,pebutton.getPosition().y + pebutton.getSize().y/2.f});
		//ДЕЛАЕМ ШКАЛЫ ДЛЯ ПАРАМЕТРОВ
		
		const float barWidth = 150.f;
		const float barHeight = 20.f;
		const float paddingBar = 20.f;
		std::vector<int> barsnumber = { 1,2,3,4,5 };
		std::unordered_map<int, std::string > conver = {{1, "son"},{2, "talk"},{3, "mental"},{4, "bot"},{5, "body"}};
		std::vector<sf::Text> bartexts;
		std::vector<sf::RectangleShape> barbackground;
		std::vector<sf::RectangleShape> barprogress;
		const float startYbar = (800 - (barsnumber.size() * barHeight + (barsnumber.size() - 1) * paddingBar)) / 2.f - 150.f;
		const float startXbar = 0.f;
		for (size_t i = 0; i < barsnumber.size(); ++i) {
			sf::Text text(font);
			text.setString(conver.at(i+1));
			text.setFont(font);
			text.setCharacterSize(14);
			text.setFillColor(sf::Color::Black);
			sf::RectangleShape backgroundA(sf::Vector2f(barWidth, barHeight));
			backgroundA.setFillColor(sf::Color(255, 255, 255)); 
			backgroundA.setOutlineThickness(2.f);
			backgroundA.setOutlineColor(sf::Color::Black);
			backgroundA.setPosition({ startXbar,  i * (barHeight + paddingBar)+  startYbar }); // Позиция шкалы
			sf::RectangleShape progressBar(sf::Vector2f(0.f, barHeight)); // Начальная ширина 0
			progressBar.setFillColor(sf::Color(8, 32, 132)); // 
			progressBar.setPosition({ startXbar , i * (barHeight + paddingBar) + startYbar });
			text.setPosition({ backgroundA.getPosition().x,backgroundA.getPosition().y - backgroundA.getSize().y + 2.f });
			bartexts.push_back(text);
			barbackground.push_back(backgroundA);
			barprogress.push_back(progressBar);

		}
		//ДЕЛАЕМ КНОПОЧКИ

		std::vector<int> numbers = { 1, 2, 3, 4, 5, 6};
		std::vector<sf::RectangleShape> buttons;
		std::vector<sf::Text> buttonTexts;
		const float buttonWidth = 100.f;
		const float buttonHeight = 50.f;
		const float padding = 20.f;
		const float startX = (800 - (numbers.size() * buttonWidth + (numbers.size() - 1) * padding)) / 2.f;
		const float startY = 530.f;
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

		Intro intro(window);
		

		Character* someperson = intro.run();


		// std::cout << "Choose your fighter:" << "\n" << "press 1 if you like bot" << "\n" << "press 2 if you are just a chill guy" << "\n" << "press 3 if you are average" << std::endl;
		// int player;
		// std::cin >> player;
		// if (player == 1) {
		// 	someperson = new Botenjoyer;
		// }
		// else if (player == 2) {
		// 	someperson = new Chillguy;
		// }
		// else {
		// 	someperson = new Average;
		// }
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
							int numberday = activebody.days;
							daytext.setString("Day: " + std::to_string(numberday + 1));
							window.draw(daytext);
							for (int i = 0; i < 5; ++i) {
								int num = activebody.stud->stats.at(conver.at(i + 1));
								barprogress[i].setSize(sf::Vector2f(barWidth * (num / 100.0f), barHeight)); 
								window.draw(barprogress[i]);

							}
							if (numbers[i] == 2) {
								int physic = activebody.stud->physic.value;
								subprogress[0].setSize(sf::Vector2f(subWidth * (physic / 100.0f), subHeight)); 
								window.draw(subprogress[0]);
								int math = activebody.stud->math.value;
								subprogress[1].setSize(sf::Vector2f(subWidth * (math / 100.0f), subHeight));
								window.draw(subprogress[1]);
								int proga = activebody.stud->proga.value;
								subprogress[2].setSize(sf::Vector2f(subWidth * (proga/ 100.0f), subHeight)); 
								window.draw(subprogress[2]);
							}
							if (numbers[i] == 6) {
								int pe = activebody.stud->pe.value;
								petext.setString(std::to_string(pe));
								window.draw(petext);
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
					buttons[i].setFillColor(sf::Color(200, 192, 98)); // Светло-зеленый
				}
				else {
					buttons[i].setFillColor(sf::Color(253, 246, 171)); // Обычный зеленый
				}
			}

			// РИсуем

			sf::Vector2u windowSize = window.getSize();//размеры окна
			float coefx = static_cast<float>(windowSize.x) / sizepicture.x;
			float coefy = static_cast<float>(windowSize.y) / sizepicture.y;
			backgroundSprite.setScale(sf::Vector2f(coefx, coefy));
			window.draw(backgroundSprite);
			window.draw(pebutton);
			window.draw(petext);
			window.draw(peuptext);
			window.draw(daybutton);
			window.draw(daytext);
			//Рисуем шкалы предметов
			for (size_t i = 0; i < subnumber.size(); ++i) {
				window.draw(subbackground[i]);
				window.draw(subprogress[i]);
				window.draw(subtexts[i]);
			}
			// Рисуем шкалы параметров
			for (size_t i = 0; i < barsnumber.size(); ++i) {
				window.draw(barbackground[i]);
				window.draw(bartexts[i]);
				for (int i = 0; i < 5; ++i) {
					int num = activebody.stud->stats.at(conver.at(i+1));
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

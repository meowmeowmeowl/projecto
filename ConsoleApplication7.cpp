
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include "Action.h"
#include "audiere.h"
#include "windows.h"
#include <cstdlib>
using namespace audiere;

//#include "Character.h"
//просто функция для проверки работы
void play(Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads";
	}
	
		while (true) {
		std::cout << "chose:\n 1) sleep\n 2)study\n 3)care\n 4)talk\n 5)chiil \n6)pe,\n " << std::endl;
		int a;
		std::cin >> a;
		if (a == 1) {
			std::cout << "sleep" << std::endl;
			student->actionsleep();
			meow->pressthebutton();
			student->showstats();
		}
		else if (a == 2) {
			std::cout << "study" << std::endl;
			student->actionstudy();
			meow->pressthebutton();
			student->showstats();
			student->physic.showprogress();
			student->math.showprogress();
			student->proga.showprogress();
		}
		else if (a == 3) {
			std::cout << "care" << std::endl;
			student->actioncare();
			meow->pressthebutton();
			student->showstats();
		}
		else if (a == 4) {
			std::cout << "talk" << std::endl;
			student->actionactive();
			meow->pressthebutton();
			student->showstats();
		}
		else if (a == 5) {
			std::cout << "chill" << std::endl;
			student->actionchill();
			meow->pressthebutton();
			student->showstats();
		}
		else if (a == 6) {
			std::cout << "pe" << std::endl;
			student->actionpe();
			meow->pressthebutton();
			student->showstats();
			student->pe.showprogress();
		}
		else {
			break;
		}
	}
}
int main() {
	Character* b;
	std::cout << "Choose your fighter:" << "\n" << "press 1 if you like bot" << "\n" << "press 2 if you are just a chill guy"<<"\n" << "press 3 if you are average" << std::endl;
	int player;
	std::cin >> player;
	if (player == 1) {
		b = new Botenjoyer;
	}
	else if (player == 2) {
		b = new Chillguy;
	}
	else {
		b = new Average;
	}
	b->showstats();
	Action a(b);
	play(&a);
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

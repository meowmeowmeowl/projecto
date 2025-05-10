#ifndef ACTION_H
#define ACTION_H
#include "Character.h"
#include "youdead.h"
struct Action {
	int days;
	int number_action;
	std::unordered_map<std::string, bool> tasks;
	std::vector<int> important_days;
	std::vector<int> achievement_days;
	int end_semester;
	Character* stud;
	Action(Character* student) {
		stud = student;
		days = 0;
		end_semester = 30;
		number_action = 0;
		tasks["alive"] = 1;
		tasks["physic"] = 0;
		tasks["math"] = 0;
		tasks["pe"] = 0;
		important_days = { 7,14, 23 };
		for (int i = 0; i < 5; ++i) {
			achievement_days.push_back(rand() % 30);
		}
	}
	void isalive() {
		auto it = std::find_if(stud->stats.begin(), stud->stats.end(), [](const auto& pair) {
			return pair.second == 0;
			});
		if (it != stud->stats.end()) {
			youdead("character", stud);
		}
	}
	void checkday() {
		std::cout << "Deadline uiuiui" << std::endl;
		if (stud->physic.value != stud->physic.maxx) {
			youdead("physic", stud);
		}
		stud->physic.value = 0;
		if (stud->math.value != stud->math.maxx) {
			youdead("math", stud);
		}
		stud->math.value = 0;
	}
	void semester() {
		std::cout << "o no end of semester" << std::endl;
		if (stud->pe.value != stud->pe.maxx) {
			youdead("pe", stud);
		}
		youdead("no", stud);
	}
	void pressthebutton() {
		isalive();
		number_action += 1;
		if (number_action ==1) {
			days += 1;
			number_action = 0;
			int count = std::count(important_days.begin(), important_days.end(), days);
			if (count > 0) {
				checkday();
			}
			else if (days == end_semester) {
					semester();
				}
		}
	}
	
};

















#endif // ACTION_H

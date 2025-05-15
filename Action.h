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
	void checkprivilege() {
		std::unordered_map<std::string, int> priv;
		priv["physic"] = stud->achieve.numbers[0];
		priv["math"] = stud->achieve.numbers[1];
		priv["proga"] = stud->achieve.numbers[2];
		std::vector<std::string> arezero;
		for (const auto& pair : priv) {
			if (pair.second == 0) {
				arezero.push_back(pair.first);
			}
		}
		if (!arezero.empty()) {
			std::cout << "you can improve your bot for subject if you pass it" << std::endl;
			int randomIndex = std::rand() % arezero.size();
			std::string subject = arezero[randomIndex];
			if (subject == "physic") {
				stud->achieve.physicEnjoyer();
			}
			else if (subject == "math") {
				stud->achieve.mathEnjoyer();
			}
			else {
				stud->achieve.progaEnjoyer();
			}

		}
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
		if (number_action ==3) {
			days += 1;
			number_action = 0;
			std::cout << "It is a new day" << "\n" << std::endl;

			int count = std::count(important_days.begin(), important_days.end(), days);
			int cou = std::count(achievement_days.begin(), achievement_days.end(), days);
			if (cou > 0) {
				checkprivilege();
			}
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

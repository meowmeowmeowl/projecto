#ifndef CHARACTER_H
#define CHARACTER_H
#include "Tasks.h"
#include "Achieve.h"
#include <iostream>

struct Character
{
	std::unordered_map<std::string, int> stats;
	Physic physic;
	Math math;
	Pe pe;
	Proga proga;
	Achieve achieve;
	Character() {
		stats["son"] = 60;
		stats["talk"] = 60;
		stats["mental"] = 60;
		stats["bot"] = 60;
		stats["body"] = 60;
	}
	~Character() {}
	void showstats() {//вспомогательное
		for (auto& pair : stats) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
	int checkborders(std::string stat, int par) { //выход за границы стата и счет
		int a = stats[stat];
		if (a + par >= 100) {
			return 100;
		}
		if (a + par <= 0) {
			return 0;
		}
		return a + par;


	}
	void action(std::vector<int>& parametrs) {
		int i = 0;
		for ( auto& pair : stats) {
			stats[pair.first] = checkborders(pair.first, parametrs[i]);
			i++;
		}
	}
	virtual void actionsleep() {} //поспали
	virtual void actionstudy() {} //поучились добавить к домашке
	virtual void actioncare() {} //помылись поелись
	virtual void actionchill() {} //погуляли
	virtual void actionactive() {}//посоциализировались
	virtual void actionpe() {}//уу физра


};

struct Botenjoyer : public Character {
	virtual void actionsleep() override {
		std::vector<int> parametrs = { 50, -10, 0, -10, 10 };
		action(parametrs);
	}
	virtual void actionstudy() override {
		std::vector<int> parametrs = { -10, 0, 10, 30, -10 };
		std::cout << "what to bot" << "\n" << "1 to physcis; 2 to math 3 to proga" << std::endl;
		int a;
		std::cin >> a;
		if (a == 1) {
			physic.makeoperation(stats["bot"], achieve.numbers[0]);
		}
		else if (a == 2) {
			math.makeoperation(stats["bot"], achieve.numbers[1]);
		}
		else {
			proga.makeoperation(stats["bot"], achieve.numbers[2]);
		}
		action(parametrs);
	}
	virtual void actioncare() override {
		std::vector<int> parametrs = { -10, -10, 0, -10, 30 };
		action(parametrs);
	}
	virtual void actionchill() override {
		std::vector<int> parametrs = { -10, 10, 30, -10, 0 };
		action(parametrs);
	}
	virtual void actionactive() override {
		std::vector<int> parametrs = { -10, 30, 10, 0, -10 };
		action(parametrs);
	}
	virtual void actionpe() override {
		std::vector<int> parametrs = { -10, 0, 10, -30, -10 };
		pe.makeoperation(0, 0);
		action(parametrs);

	}
};

struct Chillguy : public Character {
	virtual void actionsleep() override {
		std::vector<int> parametrs = { 40, 0, 10, -20, -10 };
		action(parametrs);
	}
	virtual void actionstudy() override {
		std::vector<int> parametrs = { -10, 10, 0, -10, -0 };
		std::cout << "what to bot" << "\n" << "1 to physcis; 2 to math 3 to proga" << std::endl;
		int a;
		std::cin >> a;
		if (a == 1) {
			physic.makeoperation(stats["bot"], achieve[0]);
		}
		else if (a == 2) {
			math.makeoperation(stats["bot"], achieve[1]);
		}
		else {
			proga.makeoperation(stats["bot"], achieve[2]);
		}
		action(parametrs);
	}
	virtual void actioncare() override {
		std::vector<int> parametrs = { -10, -10, 10, 20, 30 };
		action(parametrs);
	}
	virtual void actionchill() override {
		std::vector<int> parametrs = { 10, 0, 20, 30, 10 };
		action(parametrs);
	}
	virtual void actionactive() override {
		std::vector<int> parametrs = { -10, 30, -20, 10, -10 };
		action(parametrs);
	}
	virtual void actionpe() override {
		std::vector<int> parametrs = { -10, -10, -10, 10, -10 };
		pe.makeoperation(0,0);
		action(parametrs);
	}
};
struct Average : public Character {
	virtual void actionsleep() override {
		std::vector<int> parametrs = { 30, 0, 10, -10, -10 };
		action(parametrs);
	}
	virtual void actionstudy() override {
		std::vector<int> parametrs = { -10, 10, -10, 0, -10 };
		std::cout << "what to bot" << "\n" << "1 to physcis; 2 to math 3 to proga" << std::endl;
		int a;
		std::cin >> a;
		if (a == 1) {
			physic.makeoperation(stats["bot"], achieve[0]);
		}
		else if (a == 2) {
			math.makeoperation(stats["bot"], achieve[1]);
		}
		else {
			proga.makeoperation(stats["bot"], achieve[2]);
		}
		action(parametrs);
	}
	virtual void actioncare() override {
		std::vector<int> parametrs = { 10, -10, 10, 10, 20 };
		action(parametrs);
	}
	virtual void actionchill() override {
		std::vector<int> parametrs = { -10, 10, 10, -10, 0 };
		action(parametrs);
	}
	virtual void actionactive() override {
		std::vector<int> parametrs = { -10, 20, 10, 0, -10 };
		action(parametrs);
	}
	virtual void actionpe() override {
		std::vector<int> parametrs = { -10, 10, 110, 0, -10 };
		pe.makeoperation(0, 0);
		action(parametrs);
	}
};


#endif // CHARACTER_H
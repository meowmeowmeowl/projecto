#ifndef CHANGE_PARAMS
#define CHANGE_PARAMS
#include "Action.h"
void processNumber(int number, Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	if (number == 1) {
		std::cout << "sleep" << std::endl;
		student->actionsleep();
		meow->pressthebutton();
		student->showstats();

	}
	else if (number == 2) {
		std::cout << "study" << std::endl;
		student->actionstudy();
		meow->pressthebutton();
		student->showstats();
		student->physic.showprogress();
		student->math.showprogress();
		student->proga.showprogress();
	}
	else if (number == 3) {
		std::cout << "care" << std::endl;
		student->actioncare();
		meow->pressthebutton();
		student->showstats();
	}
	else if (number == 4) {
			std::cout << "talk" << std::endl;
			student->actionactive();
			meow->pressthebutton();
			student->showstats();
	}
	else if (number == 5) {
		std::cout << "chill" << std::endl;
		student->actionchill();
		meow->pressthebutton();
		student->showstats();
	}
	else {
		std::cout << "pe" << std::endl;
		student->actionpe();
		meow->pressthebutton();
		student->showstats();
		student->pe.showprogress();
	}

}




#endif // CHANGE_PARAMS
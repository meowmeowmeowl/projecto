#ifndef CHANGE_PARAMS
#define CHANGE_PARAMS
#include "Action.h"
void processNumber(int number, Action* meow) {
	Character* student = meow->stud;
	if (student == nullptr) {
		std::cerr << "asads" << std::endl;
	}
	if (number == 1) {
		student->actionsleep();

	}
	else if (number == 2) {
		student->actionstudy();
	}
	else if (number == 3) {
		student->actioncare();
	}
	else if (number == 4) {
			student->actionactive();
	}
	else if (number == 5) {
		student->actionchill();
	}
	else {
		student->actionpe();
	}
	meow->pressthebutton();

}




#endif // CHANGE_PARAMS
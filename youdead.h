#ifndef YOUDEAD
#define YOUDEAD

void youdead(std::string reason, Character* stud) {
	std::cout << "you know it is the end of the game any lasts words" << std::endl;
	std::string answer;
	std::cin >> answer;;
	if (answer == "refuse") {
		return;
	}
	if (reason == "pe") {
		//показать что вы умерли из за непосещаемости физры
		std::cout << "no fan of sport" << std::endl;
		exit(0);
	}
	if (reason == "no") {
		//вы не умерли просто настал конец игры
		std::cout << "succes";
		exit(1);
	}
	if (reason == "math") {
		//вас отчисилии из-за неуважения к царице наук
		std::cout << "no more gambling";
		exit(2);
	}
	if (reason == "physic") {
		//вас отчсиилил Кобякин
		std::cout << "not phystc";
		exit(3);

	}
	if (reason == "character") {
		if (stud->stats["son"] == 0) {
			//от недосыпа у вас начались голоса в голове и вас пришлось положить в больницу
			std::cout << "son";
		}
		else if (stud->stats["talk"] == 0) {
			//от  недостатка общения вы решили что настоящий физтех это только физтех конфеншс и вместо учебы пишете туда посты 
			std::cout << "talk";
		}
		else if (stud->stats["bot"] == 0) {
			std::cout << "bot";
		}
		else if (stud->stats["mental"] == 0) {
			//вы выгорели у вас началась депрессия))))))))
			std::cout << "menta;";
		}
		else if (stud->stats["body"] == 0) {
			//от того насколько вы грязный вас перестали отличать от таракана и убили пестицидами
			std::cout << "bodu";
		}
		exit(4);
	}
}



#endif // YOUDEAD
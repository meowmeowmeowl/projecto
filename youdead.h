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
		//�������� ��� �� ������ �� �� �������������� �����
		std::cout << "no fan of sport" << std::endl;
		exit(0);
	}
	if (reason == "no") {
		//�� �� ������ ������ ������ ����� ����
		std::cout << "succes";
		exit(1);
	}
	if (reason == "math") {
		//��� ��������� ��-�� ���������� � ������ ����
		std::cout << "no more gambling";
		exit(2);
	}
	if (reason == "physic") {
		//��� ��������� �������
		std::cout << "not phystc";
		exit(3);

	}
	if (reason == "character") {
		if (stud->stats["son"] == 0) {
			//�� �������� � ��� �������� ������ � ������ � ��� �������� �������� � ��������
			std::cout << "son";
		}
		else if (stud->stats["talk"] == 0) {
			//��  ���������� ������� �� ������ ��� ��������� ������ ��� ������ ������ �������� � ������ ����� ������ ���� ����� 
			std::cout << "talk";
		}
		else if (stud->stats["bot"] == 0) {
			std::cout << "bot";
		}
		else if (stud->stats["mental"] == 0) {
			//�� �������� � ��� �������� ���������))))))))
			std::cout << "menta;";
		}
		else if (stud->stats["body"] == 0) {
			//�� ���� ��������� �� ������� ��� ��������� �������� �� �������� � ����� �����������
			std::cout << "bodu";
		}
		exit(4);
	}
}



#endif // YOUDEAD
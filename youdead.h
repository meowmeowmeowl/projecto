#ifndef YOUDEAD
#define YOUDEAD
void youdead(std::string reason, std::string& intext) {
    if (reason == "pe") {
        //�������� ��� �� ������ �� �� �������������� �����
        intext =  "no fan of sport";
    }
    if (reason == "no") {
        //�� �� ������ ������ ������ ����� ����
        intext =  "Succes: now please give us otl(1)";
    }
    if (reason == "math") {
        //��� ��������� ��-�� ���������� � ������ ����
        intext =  "no more gambling";
    }
    if (reason == "physic") {
        //��� ��������� �������
        intext =  "Kobyakin has removed you";

    }
    if (reason == "son") {
        intext = "you started hearing voices in your head and had to be hospitalized";
    }
        if (reason == "talk") {
            intext =  "  you decided that the real Phystech is only Phystech.Confccions and instead of studying you write posts there";
    }
        if (reason == "bot") {
            intext =  "mom please take me home";
        }
        if (reason == "mental") {
            intext =  "burnout and depression";
        }
     if(reason == "body"){
         intext =  "you were so dirty people thought yoy are cockroach";

    }
}

#endif // YOUDEAD
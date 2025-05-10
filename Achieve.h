#ifndef ACHIEVE_H
#define ACHIEVE_H
struct Achieve {
    size_t size = 3;
    std::vector<int> numbers;
    Achieve() : numbers(size, 0) {}
 /*0 - +10 ��������� � ���� ��������
 1 - 10 ��������� � ���� ������ 
 ��������� �� ��������� */

 // ���������� �������� ��������������
    int& operator[](size_t index) {
        return numbers[index]; 
    }

    // ����������� ������ ��������� ��������������
    const int& operator[](size_t index) const {
        return numbers[index]; 
    }
    void PhysicEnjoyer() {
        numbers[0] = 1;
        
 }
    void MathEnjoyer() {
        numbers[1] = 1;
    }
    void ProgaEnjoyer() {
        numbers[2] = 1;
    }

};

#endif // ACHIEVE_H
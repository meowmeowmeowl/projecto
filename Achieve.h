#ifndef ACHIEVE_H
#define ACHIEVE_H
struct Achieve {
    size_t size = 3;
    std::vector<int> numbers;
    Achieve() : numbers(size, 0) {}
 /*0 - +10 процентов к боту общефизв
 1 - 10 процентов к боту матана 
 остальное не придумала */

 // Определяем оператор индексирования
    int& operator[](size_t index) {
        return numbers[index]; 
    }

    // Константная версия оператора индексирования
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
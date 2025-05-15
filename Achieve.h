#ifndef ACHIEVE_H
#define ACHIEVE_H
struct Achieve {
    size_t size = 3;
    std::vector<int> numbers;
    Achieve() : numbers(size, 0) {}
 /*0 - +10 процентов к боту общефизв */

 // Определяем оператор индексирования
    int& operator[](size_t index) {
        return numbers[index]; 
    }

    // Константная версия оператора индексирования
    const int& operator[](size_t index) const {
        return numbers[index]; 
    }
    void physicEnjoyer() {
        std::cout << "smth for test choose" << std::endl;
        int e;
        std::cin >> e;
        if (e == 1) {
            std::cout << "you imporve phys" << std::endl;
            numbers[0] = 1;
        }
        else {
            std::cout << "adasdada" << std::endl;
        }
        
 }
    void mathEnjoyer() {
        std::cout << "smth for test choose" << std::endl;
        int e;
        std::cin >> e;
        if (e == 1) {
            std::cout << "you imporve math" << std::endl;
            numbers[1] = 1;
        }
        else {
            std::cout << "adasdada" << std::endl;
        }
      
    }
    void progaEnjoyer() {
        std::cout << "smth for test choose" << std::endl;
        int e;
        std::cin >> e;
        if (e == 1) {
            std::cout << "you imporve proga" << std::endl;
            numbers[2] = 1;
        }
        else {
            std::cout << "adasdada" << std::endl;
        }
    }

};

#endif // ACHIEVE_H
#ifndef TASKS_H
#define TASKS_H
# include <iostream>
# include <unordered_map>
# include <string>
# include <vector>

struct Study {
    float value;
    float change;
    float maxx;

    virtual bool task() { return 1; }
  virtual void makeoperation(int k, bool f) {
      if (task()) {
      value = value + change * (1 + k / 100.0f);
      if (f) { value = 1.1 * value; }
      if (value > maxx) {
          value = maxx;
      }
  }
}
//вспомогательное
virtual void showprogress() {
}
};

struct Physic:Study {
    Physic() {
        value = 0;
        change = 10;
        maxx = 100;
    }
    void showprogress() {
        std::cout << "how is physic:" << value << std::endl;
    }
    bool task() {
        std::cout << "some smart question enter 3 to make"<<std::endl;
        int a;
        std::cin >> a;
        if (a == 3) {
            std::cout << "good" << std::endl;
            return 1;
        }
        std::cout << "you failed sorry bro"<<std::endl;
        return 0;
    }
};
struct Proga :Study {
    Proga() {
        value = 0;
        change = 10;
        maxx = 100;
    }
    void showprogress() {
        std::cout << "how is proga:" << value << std::endl;
    }
    bool task() {
        std::cout << "some smart question enter 2 to make";
        int a;
        std::cin >> a;
        if (a == 2) {
            return 1;
        }
        std::cout << "you failed sorry bro";
        return 0;
    }
};
struct Math:Study {
    Math() {
      value = 0;
      change = 20;
      maxx = 200;
    }
    void showprogress() {
        std::cout << "how is math:" << value << std::endl;
    }
    bool task() {
        std::cout << "some smart question enter 1 to make";
        int a;
        std::cin >> a;
        if (a == 1) {
            return 1;
        }
        std::cout << "you failed sorry bro";
        return 0;
    }

};
struct Pe:Study {
    Pe() {
        value = 0;
        maxx = 25;
        change = 0;
    }
    void makeoperation(int k, bool f) {
        value = value + 1;
        if (value > maxx) {
            value = maxx;
        }
    }
};

#endif // TASKS_H
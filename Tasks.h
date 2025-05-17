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
    bool tas;
  virtual void makeoperation(int k, bool f) {;
      if (tas) {
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
    

};
struct Proga :Study {
    Proga() {
        value = 0;
        change = 10;
        maxx = 100;
        tas = 1;
    }
    void showprogress() {
        std::cout << "how is proga:" << value << std::endl;
    }
    
};
struct Math:Study {
    Math() {
      value = 0;
      change = 10;
      maxx = 100;
      tas = 1;
    }
    void showprogress() {
        std::cout << "how is math:" << value << std::endl;
    }

};
struct Pe:Study {
    Pe() {
        value = 0;
        tas = 1;
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
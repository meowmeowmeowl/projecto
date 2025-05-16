#ifndef TASKS_H
#define TASKS_H
#include <string>

struct TaskResult {
    std::string prompt;
    int expectedAnswer;
    bool needsInput;
};

struct Study {
    float value;
    float change;
    float maxx;

    virtual TaskResult task() { return {"", 0, false}; }
    virtual void makeoperation(int k, bool f) {
        TaskResult result = task();
        if (!result.needsInput || result.expectedAnswer == -1) { // -1 indicates task success without input
            value = value + change * (1 + k / 100.0f);
            if (f) { value = 1.1 * value; }
            if (value > maxx) {
                value = maxx;
            }
        }
    }
    virtual void showprogress() {
}
};

struct Physic : Study {
    Physic() {
        value = 0;
        change = 10;
        maxx = 100;
    }
    TaskResult task() override {
        return {"Enter 3 to complete physics task", 3, true};
    }
};

struct Proga : Study {
    Proga() {
        value = 0;
        change = 10;
        maxx = 100;
    }
    TaskResult task() override {
        return {"Enter 2 to complete programming task", 2, true};
    }
};

struct Math : Study {
    Math() {
        value = 0;
        change = 20;
        maxx = 200;
    }
    TaskResult task() override {
        return {"Enter 1 to complete math task", 1, true};
    }
    void makeoperation(int k, bool f) override {
        TaskResult result = task();
        if (!result.needsInput || result.expectedAnswer == -1) {
            value = value + change * (1 + k / 100.0f);
            if (f) { value = 1.1 * value; }
            if (value > maxx) {
                value = maxx;
            }
        }
    }
};

struct Pe : Study {
    Pe() {
        value = 0;
        maxx = 25;
        change = 0;
    }
    void makeoperation(int k, bool f) override {
        value = value + 1;
        if (value > maxx) {
            value = maxx;
        }
    }
};

#endif // TASKS_H
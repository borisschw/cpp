#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::find

class Observer; // Forward declaration

class Subject {
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
            std::cout << "Observer removed." << std::endl;
        }
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

class Observer {
public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Received an update." << std::endl;
    }
};

int main() {
    Subject subject;

    Observer* observer1 = new ConcreteObserver();
    Observer* observer2 = new ConcreteObserver();

    subject.addObserver(observer1);
    subject.addObserver(observer2);

    subject.notifyObservers();

    subject.removeObserver(observer1);

    subject.notifyObservers();

    delete observer1;
    delete observer2;

    return 0;
}

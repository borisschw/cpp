#include <iostream>

// Abstract base class representing the strategy
class Strategy {
public:
    virtual void execute() const = 0; // Pure virtual function
};

// Concrete strategy classes
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy A." << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy B." << std::endl;
    }
};

class ConcreteStrategyC : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing strategy C." << std::endl;
    }
};

// Context class
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    // Create strategies
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;
    ConcreteStrategyC strategyC;

    // Create context and set initial strategy
    Context context(&strategyA);

    // Execute the current strategy
    context.executeStrategy();

    // Change the strategy at runtime
    context.setStrategy(&strategyB);
    context.executeStrategy();

    // Change the strategy again
    context.setStrategy(&strategyC);
    context.executeStrategy();

    return 0;
}

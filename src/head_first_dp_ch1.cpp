#include <iostream>
#include <functional>
class FlyBehavior{
public:
    virtual void fly() const= 0;
};

class FlyWithWings:public FlyBehavior{
public:
    void fly()const override {
        std::cout<<"I'm flying!!!" << std::endl;
    }
};


class FlyNoWay:public  FlyBehavior{
public:
    void fly()const override{
        std::cout<<"I can't fly." << std::endl;
    }
};

class QuackBehavior {
    public:
    virtual void quack()const =0;
};

class Quack:public QuackBehavior{
    public:
    void quack()const override {
        std::cout << "Quack " <<std::endl;
    }
};

class MuteQuack:public QuackBehavior {
    public:
    void quack()const override {
        std::cout<<"<< Silence >>"<<std::endl;
    }
};

class Squeak:public QuackBehavior {
    public:
    void quack()const override {
        std::cout<<"Squeak"<<std::endl;
    }
};

class Duck
{
    private:
    FlyBehavior *fb ;
    QuackBehavior *qb;

    public:
    Duck(FlyBehavior *fb, QuackBehavior *qb): fb(fb), qb(qb){}

    void setFlyBehaviour(FlyBehavior *fb){
            this->fb = fb;
        }

    void setQuckBehaviour(QuackBehavior *qb){
        this->qb = qb;
    }

    void display(){
        std::cout<<"display duck!" << std::endl;
    }
    void performFly() const
    {
        fb->fly();
    }

    void performQuack()const
    {
        qb->quack();
    }

    void swim() {
    std::cout<<"All ducks float, even decoys!" << std::endl;
    }

    private:
    std::function<void()> m_Callback;

};

int main()
{

    FlyWithWings reallyFly;
    FlyNoWay nofly;
    Quack quak;
    Squeak squeak;
    Duck duck(&nofly, &quak);

    duck.performFly();
    duck.performQuack();

    duck.setFlyBehaviour(&reallyFly);
    duck.setQuckBehaviour(&squeak);

    duck.performFly();
    duck.performQuack();


    return 0;
}
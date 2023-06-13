#include <iostream>
#include <functional>
class FlyBehavior{
public:
    virtual void fly() const= 0;
};

class FlyRocketPowered:public FlyBehavior{
public:
    void fly()const override {
        std::cout<<"I'm flying like a rocket!!!" << std::endl;
    }
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


class DuckCall{

    private:
    QuackBehavior *qb;
    public:
    DuckCall(QuackBehavior *qb): qb(qb){}


    void performQuack()const
    {
        qb->quack();
    }

    void setQuckBehaviour(QuackBehavior *qb){
        this->qb = qb;
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
};

int main()
{
    //different "strategies"
    FlyWithWings reallyFly;
    FlyNoWay nofly;
    FlyRocketPowered rocket_fly;

    Quack quak;
    Squeak squeak;


    Duck duck(&nofly, &quak);

    DuckCall duck_call(&quak);

    duck.performFly();
    duck.performQuack();

    duck.setFlyBehaviour(&reallyFly);
    duck.setQuckBehaviour(&squeak);


    duck.performFly();
    duck.performQuack();

    duck.setFlyBehaviour(&rocket_fly);
    duck.performFly();

    std::cout<<"duck call"<<std::endl;
    duck_call.performQuack();

    return 0;
}
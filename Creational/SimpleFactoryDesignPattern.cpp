#include <iostream>
using namespace std;

class Burger {
    public:
    virtual void prepare() = 0 ;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Basic Burger wiht Bun!" << endl;
    }
};

class StandardBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing standard Burger with meat!!" << endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Premium burger!!" << endl;
    }
};

class BurgerFactory {
    public:
    Burger* createBurger(string& type){
        if( type == "basic"){
            return new BasicBurger();
        }else if(type == "standard"){
            return new StandardBurger();
        }else if(type == "premium"){
            return new PremiumBurger();
        }else{
            cout << "Invalid Burger Type!!" << endl;
            return nullptr;
        }

    }
};

int main (){
    string type  = "standard";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}

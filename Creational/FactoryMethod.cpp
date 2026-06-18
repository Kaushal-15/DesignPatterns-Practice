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
class BasicWheatBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Basic Burger wiht Wheat!" << endl;
    }
};

class StandardWheatBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing standard Burger with meat and Wheat!!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Premium burger with Wheat!!" << endl;
    }
};

class BurgerFactory {
    public:
    virtual Burger* createBurger(string& type) = 0;
};
class ZingBurger : public BurgerFactory{
    public:
    Burger *createBurger(string& type) override {
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

class WheatBurger : public BurgerFactory{
    public:
    Burger *createBurger(string& type) override {
        if( type == "basic"){
            return new BasicWheatBurger();
        }else if(type == "standard"){
            return new StandardWheatBurger();
        }else if(type == "premium"){
            return new PremiumWheatBurger();
        }else{
            cout << "Invalid Burger Type!!" << endl;
            return nullptr;
        }

    }
};
int main (){
    string type  = "standard";
    BurgerFactory* myBurgerFactory = new WheatBurger();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}

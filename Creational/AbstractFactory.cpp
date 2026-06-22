#include <iostream>
#include <string>

using namespace std;

// Base interfaces
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() = default;
};

// --- Regular Burgers ---
class BasicBurger : public Burger {
public:
    void prepare() override { cout << "Preparing basic burger with regular bun\n"; }
};

class StandardBurger : public Burger {
public:
    void prepare() override { cout << "Preparing standard burger with meat\n"; }
};

class PremiumBurger : public Burger {
public:
    void prepare() override { cout << "Preparing premium burger\n"; }
};

// --- Wheat Burgers ---
class BasicWheatBurger : public Burger {
public:
    void prepare() override { cout << "Preparing basic burger with wheat bun\n"; }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override { cout << "Preparing standard meat burger with wheat bun\n"; }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override { cout << "Preparing premium wheat burger\n"; }
};

// --- Garlic Breads ---
class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override { cout << "Preparing basic garlic bread\n"; }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override { cout << "Preparing cheese garlic bread\n"; }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override { cout << "Preparing basic wheat garlic bread\n"; }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override { cout << "Preparing cheese wheat garlic bread\n"; }
};

// --- Factories ---
class BurgerFactory {
public:
    virtual Burger* createBurger(const string& type) = 0;
    virtual GarlicBread* createGarlicBread(const string& type) = 0; 
    virtual ~BurgerFactory() = default;
};

class ZingBurger : public BurgerFactory {
public:
    Burger* createBurger(const string& type) override {
        if (type == "basic") return new BasicBurger();
        if (type == "standard") return new StandardBurger();
        if (type == "premium") return new PremiumBurger();
        
        cout << "Invalid burger type: " << type << "\n";
        return nullptr;
    }

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "basic") return new BasicGarlicBread();
        if (type == "cheese") return new CheeseGarlicBread();
        
        cout << "Invalid garlic bread type: " << type << "\n";
        return nullptr;
    }
};

class WheatBurger : public BurgerFactory {
public:
    Burger* createBurger(const string& type) override {
        if (type == "basic") return new BasicWheatBurger();
        if (type == "standard") return new StandardWheatBurger();
        if (type == "premium") return new PremiumWheatBurger();
        
        cout << "Invalid burger type: " << type << "\n";
        return nullptr;
    }

    GarlicBread* createGarlicBread(const string& type) override {
        if (type == "basic") return new BasicWheatGarlicBread();
        if (type == "cheese") return new CheeseWheatGarlicBread();
        
        cout << "Invalid garlic bread type: " << type << "\n";
        return nullptr;
    }
};

int main() {
    string burgerType = "standard";
    string breadType = "cheese";
    
    BurgerFactory* factory = new WheatBurger();
    
    Burger* myBurger = factory->createBurger(burgerType);
    if (myBurger) myBurger->prepare();
    
    GarlicBread* myBread = factory->createGarlicBread(breadType);
    if (myBread) myBread->prepare();
    
    return 0;
}
#include <iostream>
using namespace std;

//Strategy interface or the abstract class for Walk
class WalkableRobot{
    public :
    virtual void walk() =0;
    virtual ~WalkableRobot(){}
};

//Concrete Strategies for walk
class NormalWalk : public WalkableRobot{
    public:
    void walk() override {
        cout << "Walking normally..." << endl;
    }
};

class Nowalk : public WalkableRobot{
    public:
    void walk() override{
        cout << "Cannot Walk.." << endl;
    }
};

//Strategy interface or the abstract class for Talk
class TalkableRobot{
    public:
    virtual void Talk() = 0;
    virtual ~TalkableRobot(){}
};

class NormalTalk : public TalkableRobot{
    public:
    void Talk() override{
        cout << "Can Talk..." << endl;
    }
};

class NoTalk : public TalkableRobot{
    public:
    void Talk() override{
        cout << "Cannot Talk..." << endl;
    }
};

class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

// --- Robot Base Class ---
class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
       
    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->Talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

// --- Concrete Robot Types ---
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new Nowalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}
#include <iostream>

using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class Unit
{
public:
    void on()
    {
        cout << "The unit is ready\n";
    }
    void off()
    {
        cout << "The unit is not ready\n";
    }
};


class UnitOnCommand : public Command {
public:
    UnitOnCommand(Unit* unit) : mUnit(unit) {}
    void execute() {
        mUnit->on();
    }
private:
    Unit* mUnit;
};


class UnitOffCommand : public Command {
public:
    UnitOffCommand(Unit* unit) : mUnit(unit) {}
    void execute() {
        mUnit->off();
    }
private:
    Unit* mUnit;
};



class RemoteControl {
public:
    void setCommand(Command* cmd) {
        mCmd = cmd;
    }
    void buttonPressed() {
        mCmd->execute();
    }
private:
    Command* mCmd;
};

// The client
int main() {

    Unit* unit = new Unit;


    UnitOnCommand* unitOn = new UnitOnCommand(unit);
    UnitOffCommand* unitOff = new UnitOffCommand(unit);


    RemoteControl* control = new RemoteControl;


    control->setCommand(unitOn);
    control->buttonPressed();
    control->setCommand(unitOff);
    control->buttonPressed();

    delete unit, unitOn, unitOff, control;

    return 0;
}
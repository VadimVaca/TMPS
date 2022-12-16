#include <iostream>
#include <string>

using namespace std;
/* Prototype base class. */
class Aircraft //Prototype
{
protected:
    
    string value;

public:
    virtual Aircraft* clone() = 0;

    string getValue()
    {
        return value;
    }
};

class ConcreteAircraft : public Aircraft  //ConcretePrototype
{
public:
    ConcreteAircraft(string color)
    {
        value = color;
    }

    Aircraft* clone()
    {
        return new ConcreteAircraft(*this);
    }
};



/* Factory that manages prorotype instances and produces their clones. */
class Factory
{
    static Aircraft* copy1;
    static Aircraft* copy2;


public:
    static void  initialize()
    {
        copy1 = new ConcreteAircraft("red");
        copy2 = new ConcreteAircraft("green");
    }

    static Aircraft* getAircraftRed()
    {
        return copy1->clone();
    }

    static Aircraft* getAircraftGreen()
    {
        return copy2->clone();
    }

};

Aircraft* Factory::copy1 = 0;
Aircraft* Factory::copy2 = 0;


int main()
{
    Factory::initialize();
    Aircraft* object;

    /* All the object were created by cloning the prototypes. */
    object = Factory::getAircraftRed(); //red
    cout << object->getValue() << endl;

    object = Factory::getAircraftGreen(); //green
    cout << object->getValue() << endl;



    return 0;
}
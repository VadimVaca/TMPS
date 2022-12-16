#include <iostream>
#include <string>

/* Implemented interface. */
class AbstractInterface
{
public:
    virtual void someFunctionality() = 0;
};

/* Interface for internal implementation that Bridge uses. */
class ImplementationInterface
{
public:
    virtual void anotherFunctionality() = 0;
};

/* The Bridge */
class Bridge : public AbstractInterface
{
protected:
    ImplementationInterface* implementation;

public:
    Bridge(ImplementationInterface* backend)
    {
        implementation = backend;
    }
};

/* Different special cases of the interface. */

class UseCase1 : public Bridge
{
public:
    UseCase1(ImplementationInterface* backend)
        : Bridge(backend)
    {}

    void someFunctionality()
    {
        std::cout << "Factory in Seatle for  ";
        implementation->anotherFunctionality();
    }
};

class UseCase2 : public Bridge
{
public:
    UseCase2(ImplementationInterface* backend)
        : Bridge(backend)
    {}

    void someFunctionality()
    {
        std::cout << "Factory in Toulouse for ";
        implementation->anotherFunctionality();
    }
};

/* Different background implementations. */

class Boeing : public ImplementationInterface
{
public:
    void anotherFunctionality()
    {
        std::cout << "Boeing" << std::endl;
    }
};

class Airbus : public ImplementationInterface
{
public:
    void anotherFunctionality()
    {
        std::cout << "Airbus" << std::endl;
    }
};

int main()
{
    AbstractInterface* useCase = 0;
    ImplementationInterface* NBoeing = new Boeing;
    ImplementationInterface* NAirbus = new Airbus;


    /* First case */
    useCase = new UseCase1(NBoeing);
    useCase->someFunctionality();

    /* Second case */
    useCase = new UseCase2(NAirbus);
    useCase->someFunctionality();


    return 0;
}
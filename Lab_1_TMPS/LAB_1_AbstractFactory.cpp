#include <iostream>
#include <string>

using namespace std;

class AbstractProductA
{
public:
    virtual ~AbstractProductA() {};
    virtual  string UsefulFunctionA() const = 0;
};

/*
 * Конкретные продукты создаются соответствующими Конкретными Фабриками.
 */
class ConcreteProductA1 : public AbstractProductA
{
public:
     string UsefulFunctionA() const override 
     {
        return "B737";
     }
};

class ConcreteProductA2 : public AbstractProductA 
{
     string UsefulFunctionA() const override
     {
        return "F-17.";
     }
};





class AbstractFactory 
{
public:
    virtual AbstractProductA* CreateProductA() const = 0;
};


class ConcreteFactory1 : public AbstractFactory
 {
public:
    AbstractProductA* CreateProductA() const override
    {
        return new ConcreteProductA1();
    }
};

/**
 * Каждая Конкретная Фабрика имеет соответствующую вариацию продукта.
 */
class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA* CreateProductA() const override
    {
        return new ConcreteProductA2();
    }

};



void ClientCode(const AbstractFactory& factory)
{
    const AbstractProductA* product_a = factory.CreateProductA();   
    cout << product_a->UsefulFunctionA() << "\n";
    delete product_a;

}

int main()
{
    cout << "Client: Civil Aircraft:\n";
    ConcreteFactory1* f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    cout <<  endl;

    cout << "Client: Military Aircraft:\n";
    ConcreteFactory2* f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    cout << endl;
    return 0;
}
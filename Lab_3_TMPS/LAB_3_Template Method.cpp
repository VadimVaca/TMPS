#include <iostream>
using namespace std;

class Base
{
    void a()
    {
        cout << "a  ";
    }
    void c()
    {
        cout << "c  ";
    }
    void e()
    {
        cout << "e  ";
    }
    // 2. Для шагов, требующих особенной реализации, определите 
    //    "замещающие" методы.
    virtual void ph1() = 0;
    virtual void ph2() = 0;
public:
    // 1. Стандартизуйте основу алгоритма в шаблонном методе 
    //    базового класса
    void execute()
    {
        a();
        ph1();
        c();
        ph2();
        e();
    }
};

class One : public Base
{
    // 3. Производные классы реализуют "замещающие" методы.
    /*virtual*/void ph1()
    {
        cout << "b  ";
    }
    /*virtual*/void ph2()
    {
        cout << "d  ";
    }
};

class Two : public Base
{
    /*virtual*/void ph1()
    {
        cout << "2  ";
    }
    /*virtual*/void ph2()
    {
        cout << "4  ";
    }
};

int main()
{
    Base* array[] =
    {
       &One(), &Two()
    };
    for (int i = 0; i < 2; i++)
    {
        array[i]->execute();
        cout << '\n';
    }
}
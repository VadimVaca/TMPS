#include <iostream>

class Singleton
{
public:
    // This is how clients can access the single instance
    static Singleton* getInstance();
    void setValue(int val)
    {
        value = val;
    }
    int  getValue()
    {
        return(value);
    }
    int  factorial()
    {
        int result = 1;
        for (int i = 1; i <= value; i++)
        {
            result *= i;
        }
        return(result);
    }

private:
    int value;
    static Singleton* inst_;   // The one, single instance
    Singleton() : value(3) {} // приватный конструктор (по умолчанию value = 3)
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};

// Define the static Singleton pointer
Singleton* Singleton::inst_ = NULL;

Singleton* Singleton::getInstance()
{
    if (inst_ == NULL)
    {
        inst_ = new Singleton();
    }
    return(inst_);
}

using namespace std;

int main()
{
    /*
    p1 устанавливает значение
    p2 считает и получает
    это означает что исползуют один и тот же экземпляр класса
    */
    /*----------------------Singleton----------------------*/

    int a;
    cout << "Number = ";
    cin >> a;
    Singleton* p1 = Singleton::getInstance();
    p1->setValue(a);
    Singleton* p2 = Singleton::getInstance();
    cout << "Value = " << p2->factorial() << '\n';

}
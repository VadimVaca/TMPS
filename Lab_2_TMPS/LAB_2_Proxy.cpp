#include <iostream>
using namespace std;

 
class Interface_PaySys 
{
public:
    virtual double CreditCard(double) = 0;
    virtual double PaymentCheck(double) = 0;
    virtual double TrevelCheck(double) = 0;

};

/**
 * "Real Subject"
 */
class PaySys : public Interface_PaySys 
{
public:
    virtual double CreditCard(double x)
    {
        return x;
    }
    
    virtual double PaymentCheck(double x)
    {
        return x;
    }
    
    virtual double TrevelCheck(double x)
    {
        return x;
    }   

};

/**
 * "Proxy Object"
 */
class PaySysProxy : public Interface_PaySys 
{
public:
    PaySysProxy()
    {
        paySys = new PaySys();
    }
    virtual ~PaySysProxy()
    {
        delete paySys;
    }


    virtual double CreditCard(double x)
    {
        return paySys->CreditCard(x);
        
    }
    
    virtual double PaymentCheck(double x)
    {
        return paySys->PaymentCheck(x);
    }
    
    virtual double TrevelCheck(double x)
    {
        return paySys->TrevelCheck(x);
    }
    
private:
    Interface_PaySys* paySys;
};




int main()
{
    // Create PaySys proxy
    Interface_PaySys* proxy = new PaySysProxy();


    cout << "Menu options: " << endl << endl;
    cout << "  1 - Pay by CreditCard" << endl;
    cout << "  2 - Pay by PaymentCheck" << endl;
    cout << "  3 - Pay by TrevelCheck" << endl << endl;

    int choice;
    cout << "Select Payment System: ";
    cin >> choice;
    double amount;

    cout << "Enter amount: ";
    cin >> amount;
    if      (choice == 1) cout << "Your payment in the amount \$" << proxy->CreditCard(amount)   << " paid by CreditCard" << endl;
    else if (choice == 2) cout << "Your payment in the amount \$" << proxy->PaymentCheck(amount) << " paid by PaymentCheck" << endl;
    else if (choice == 3) cout << "Your payment in the amount \$" << proxy->TrevelCheck(amount)  << " paid by TrevelCheck" << endl;

    // Do the PaySys
    
}
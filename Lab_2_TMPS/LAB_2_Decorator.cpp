#include <iostream>
using namespace std;

class Aircraft
{
public:
    virtual void do_it() {
        cout << endl<< "Aircraft:\n";
    }
};

class Aircraft_with_Navigation_Systems : public Aircraft
{
public:
    /*virtual*/
    void do_it() {
        Aircraft::do_it();
        do_NS();
    };
private:
    void do_NS() {
        cout << " - add Navigation Systems\n";
    }
};

class Aircraft_with_Power : public Aircraft {
public:
    /*virtual*/
    void do_it() {
        Aircraft::do_it();
        do_PW();
    }
protected:
    void do_PW()
    {
        cout << " - add Power\n";
    }
};

class Aircraft_with_Lux_Salon : public Aircraft {
public:
    /*virtual*/
    void do_it() {
        Aircraft::do_it();
        do_LS();
    }
protected:
    void do_LS() {
        cout << " - add Lux_Salon\n";
    }
};

class NS_PW : public Aircraft_with_Navigation_Systems, public Aircraft_with_Power
{
public:
    /*virtual*/
    void do_it() {
        Aircraft_with_Navigation_Systems::do_it();
        Aircraft_with_Power::do_PW();
    }
};
class NS_LS : public Aircraft_with_Navigation_Systems, public Aircraft_with_Lux_Salon
{
public:
    /*virtual*/
    void do_it() {
        Aircraft_with_Navigation_Systems::do_it();
        Aircraft_with_Lux_Salon::do_LS();
    }
};
class LS_PW : public Aircraft_with_Lux_Salon, public Aircraft_with_Power
{
public:
    /*virtual*/
    void do_it() {
        Aircraft_with_Lux_Salon::do_it();
        Aircraft_with_Power::do_PW();
    }
};

class NS_PW_LS : public Aircraft_with_Navigation_Systems, public Aircraft_with_Power, public Aircraft_with_Lux_Salon
{
public:
    /*virtual*/
    void do_it() {
        Aircraft_with_Navigation_Systems::do_it();
        Aircraft_with_Power::do_PW();
        Aircraft_with_Lux_Salon::do_LS();
    }
};

int main()
{
    Aircraft_with_Navigation_Systems A_NS;
    Aircraft_with_Power A_PW;
    Aircraft_with_Lux_Salon A_LS;
    NS_PW A_NS_PW;
    NS_LS A_NS_LS;
    LS_PW A_LS_PW;
    NS_PW_LS A_NS_PW_LS;



    int choice;

    cout << "Menu options: "<<endl << endl;
    cout << "  1 - Add Navigation Systems" << endl;
    cout << "  2 - Add Power" << endl;
    cout << "  3 - Add Lux Salon" << endl;
    cout << "  4 - Add Navigation Systems + Power" << endl;
    cout << "  5 - Add Navigation Systems + Lux Salon" << endl;
    cout << "  6 - Add Lux Salon + Power" << endl;
    cout << "  7 - Add Navigation Systems + Lux Salon + Power" << endl;
    cout << "  0 - EXIT" << endl << endl;

    cout << "Select options: ";
    cin >> choice;

        if (choice == 1)
            A_NS.do_it();
        else if (choice == 2)
            A_PW.do_it();
        else if (choice == 3)
            A_LS.do_it();
        else if (choice == 4)
            A_NS_PW.do_it();
        else if (choice == 5)
            A_NS_LS.do_it();
        else if (choice == 6)
            A_LS_PW.do_it();
        else if (choice == 7)
            A_NS_PW_LS.do_it();
        else
            exit;
   
}
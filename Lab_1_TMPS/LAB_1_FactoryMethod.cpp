#include <iostream>
#include <vector>

using namespace std;

class Aircraft
{
public:
    virtual void order() = 0;
};

class B737 : public Aircraft
{
public:
    void order()
    {
        cout << "Boeing 737\n";
    }
};
class B787 : public Aircraft
{
public:
    void order()
    {
        cout << "Boeing 787\n";
    }
};


int main()
{
    vector<Aircraft*> roles;
    int choice;

    while (true)
    {
        cout << "B737(1) B787(2) Go(0): ";
        cin >> choice;
        if (choice == 0)
            break;
        else if (choice == 1)
            roles.push_back(new B737);
        else  (choice == 2);
            roles.push_back(new B787);
    }
    for (int i = 0; i < roles.size(); i++)
        roles[i]->order();
    for (int i = 0; i < roles.size(); i++)
        delete roles[i];
}
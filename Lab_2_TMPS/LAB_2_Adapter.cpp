#include <iostream>
#include <string>

using namespace std;

typedef int Cable; 

//исходный
class EuropeanSocketInterface
{
public:
    virtual int voltage() = 0;
    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
    virtual Cable earth() = 0;
};

class Socket : public EuropeanSocketInterface
{
public:
    int voltage() { return 230; }

    Cable live() { return 1; }
    Cable neutral() { return -1; }
    Cable earth() { return 0; }
};

/* целевой интерфейс */
class USASocketInterface
{
public:
    virtual int voltage() = 0;

    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
};

class Adapter : public USASocketInterface
{
    EuropeanSocketInterface* socket;

public:
    void plugIn(EuropeanSocketInterface* outlet)
    {
        socket = outlet;
    }
    int voltage() { return 110; }
    Cable live() { return socket->live(); }
    Cable neutral() { return socket->neutral(); }
};


class Electricunit
{
    USASocketInterface* power;

public:
    void plugIn(USASocketInterface* supply)
    {
        power = supply;
    }

    void work()
    {
        if (power->voltage() > 110)
        {
            cout << "Doesnt work" << endl;
            return;
        }

        if (power->live() == 1 && power->neutral() == -1)
        {
            cout << "Work normaly" << endl;
        }
    }
};


int main()
{
    Socket* socket = new Socket;
    Adapter* adapter = new Adapter;
    Electricunit* unit = new Electricunit;

    adapter->plugIn(socket);
    unit->plugIn(adapter);

    unit->work();

    return 0;
}

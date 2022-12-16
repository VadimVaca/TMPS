#include <iostream>
#include <string>
/*
737-8; CFM56-7;
777-3
787-9
*/

using namespace std;

 // Aircraft parts 

class Fuselage //фюзеляж
{
public:
    string type_of_fuselage;
    int diametr; //mm
};

class Engine //двигатель
{
public:
    string manufacturer; //производитель
    int thrust; //тяга (H)
};

class Wing
{
public:
    double wing_square;
};

class Empennage //оперение 
{
public:
    string type;
};

class Avionics // авионика
{
public:
    string electronic_systems[9];
};



// Final product - a Aircraft 
class Aircraft
{
public:
    Fuselage* fuselage;
    Engine* engine[2];
    Wing* wing;
    Empennage* empennage;
    Avionics* avionics;

    void specifications()
    {
         cout << "Fuselage Type: " << fuselage->type_of_fuselage <<  endl;
         cout << "Fuselage Size: " << fuselage->diametr << endl;
         cout << "First engine manufacturer: " << engine[0]->manufacturer<< endl;
         cout << "First engine thrust: " << engine[0]->thrust <<" kH" << endl;
         cout << "Second engine manufacturer: " << engine[1]->manufacturer << endl;
         cout << "Second engine thrust: " << engine[1]->thrust << " kH" << endl;
         cout << "Wing sqare: " << wing->wing_square << " m2" << endl;
         cout << "Empennage: " << empennage->type << endl;
         cout << "Avionics: " << avionics->electronic_systems[0] << endl;

    }
};

/* Builder is responsible for constructing the smaller parts */
class Builder
{
public:

    virtual Fuselage* getfuselage() = 0;
    virtual Engine* getengine() = 0;
    virtual Wing* getwing() = 0;
    virtual Empennage* getempennage() = 0;
    virtual Avionics* getavionics() = 0;
};

/* Director is responsible for the whole process */
class Director
{
    Builder* builder;

public:
    void setBuilder(Builder* newBuilder)
    {
        builder = newBuilder;
    }

    Aircraft* getAircraft()
    {
        Aircraft* aircraft = new Aircraft();

        aircraft->fuselage = builder->getfuselage();

        aircraft->engine[0] = builder->getengine();
        aircraft->engine[1] = builder->getengine();

        aircraft->wing = builder->getwing();

        aircraft->empennage = builder->getempennage();

        aircraft->avionics = builder->getavionics();

        return aircraft;
    }
};

/* Concrete Builder for 737 */
class Builder_737 : public Builder
{
public:
    Fuselage* getfuselage()
    {
        Fuselage* fuselage = new Fuselage();
        fuselage->type_of_fuselage = "Wide";
        fuselage->diametr = 3760;
        return fuselage;
    }

    Engine* getengine()
    {
        Engine* engine = new Engine();
        engine->manufacturer = "CFM";
        engine->thrust = 122;
        return engine;
    }

    Wing* getwing()
    {
        Wing* wing = new Wing();
        wing->wing_square = 124.6;
        return wing;
    }

    Empennage* getempennage()
    {
        Empennage* empennage = new Empennage();
        empennage->type = "standart";
        return empennage;
    }

    Avionics* getavionics()
    {
        Avionics* avionics = new Avionics();
        avionics->electronic_systems[0] = "NAV";
        return avionics;
    }

};


// Concrete Builder for 787 
class Builder_787 : public Builder
{
public:
    Fuselage* getfuselage()
    {
        Fuselage* fuselage = new Fuselage();
        fuselage->type_of_fuselage = "Wide";
        fuselage->diametr = 5490;
        return fuselage;
    }

    Engine* getengine()
    {
        Engine* engine = new Engine();
        engine->manufacturer = "GE";
        engine->thrust = 320;
        return engine;
    }

    Wing* getwing()
    {
        Wing* wing = new Wing();
        wing->wing_square = 325;
        return wing;
    }

    Empennage* getempennage()
    {
        Empennage* empennage = new Empennage();
        empennage->type = "standart";
        return empennage;
    }

    Avionics* getavionics()
    {
        Avionics* avionics = new Avionics();
        avionics->electronic_systems[0] = "NAV";
        return avionics;
    }


};

int main()
{
        Aircraft * Aircraft; // Final product
        Director director;
                
        /* A director who controls the process */
    
        /* Concrete builders */
        Builder_737 Builder_737;
        cout << "B737" << endl;
        director.setBuilder(&Builder_737); // using B737 instance
        Aircraft = director.getAircraft();
        Aircraft->specifications();
        

        cout << endl;
        /* A director who controls the process */
        
        /* Concrete builders */
        Builder_787 Builder_787;
        cout << "B787" << endl;
        director.setBuilder(&Builder_787); // using B787 instance
        Aircraft = director.getAircraft();
        Aircraft->specifications();


    return 0;
}
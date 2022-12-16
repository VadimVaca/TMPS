#include <iostream>
#include <string>
#include <map> 
using namespace std;

// "Flyweight"
class Character
{
public:
    virtual void display() const = 0;

protected:
    char mSymbol;
    int
        mWidth
        , mHeight
        , mAscent
        , mDescent
        , mPointSize
        ;
};

// "ConcreteFlyweight"
class ConcreteCharacter : public Character
{
public:
    // Constructor
    ConcreteCharacter(const char aSymbol, int aPointSize)
    {
        mSymbol = aSymbol;
        mHeight = 100;
        mWidth = 120;
        mAscent = 70;
        mDescent = 0;
        mPointSize = aPointSize;
    }

    // from Character
    virtual void display() const
    {
        std::cout << mSymbol << " ( PointSize " << mPointSize << " )\n";
    }
};


// "FlyweightFactory"
template< int POINT_SIZE = 10 >
class CharacterFactory
{

public:
    const Character& getCharacter(const char aKey)
    {

        // Uses "lazy initialization"
        Character* character = NULL;
        Characters::iterator it = mCharacters.find(aKey);


        if (mCharacters.end() == it)
        {
            switch (aKey)
            {
            case 'A': character = new ConcreteCharacter('A', POINT_SIZE); break;
            case 'B': character = new ConcreteCharacter('B', POINT_SIZE); break;

            default:  character = new ConcreteCharacter('-', POINT_SIZE); break;
            }
            mCharacters.insert(make_pair(aKey, character));
        }
        else
        {
            character = it->second;
        }

        return *character;
    }

private:
    typedef std::map< char, Character* > Characters;
    Characters mCharacters;
};


int main()
{
    std::string document = "AABBB";

    CharacterFactory<12> characterFactory;

    std::string::const_iterator it = document.begin();
    while (document.end() != it)
    {
        const Character& character = characterFactory.getCharacter(*it++);
        character.display();
    }
    return 0;
}
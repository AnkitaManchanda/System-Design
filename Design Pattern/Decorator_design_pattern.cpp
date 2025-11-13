#include<iostream>
#include<string>
using namespace std;

class Character{
    public:
    virtual string getAbilities() const = 0;
    virtual ~ Character(){}
};

class Mario: public Character{
    public: 
    string getAbilities() const override{
        return "Mario";
    }
};

class CharacterDecorator: public Character{
    protected: 
    Character* character;

    public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

class HeightUp: public CharacterDecorator{
    public:
    HeightUp(Character* c): CharacterDecorator(c){}

    string getAbilities() const override{
        return character->getAbilities() + "with height up ";
    }
};

class GunPowerUp: public CharacterDecorator{
    public:
    GunPowerUp(Character* c): CharacterDecorator(c){}

    string getAbilities() const override{
        return character->getAbilities() + "with gun ";
    }
};

class StartPowerUp: public CharacterDecorator{
    public:
    StartPowerUp(Character* c): CharacterDecorator(c){}

    string getAbilities() const override{
        return character->getAbilities() + "with start power (limited time) ";
    }

    ~StartPowerUp(){
        cout<<"Destroying star power up decorator"<<endl;
    }
};

int main(){
    Character* mario = new Mario();
    cout<<"Basic Character: "<<mario->getAbilities()<<endl;

    mario = new HeightUp(mario);
    cout<<"After HeightUp: "<<mario->getAbilities()<<endl;

    mario = new GunPowerUp(mario);
    cout<<"After GunPowerUp: "<<mario->getAbilities()<<endl;

    mario = new StartPowerUp(mario);
    cout<<"After StarPowerUp: "<<mario->getAbilities()<<endl;

    delete mario;
    return 0;
}
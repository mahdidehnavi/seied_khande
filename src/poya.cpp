#include <iostream>
#include <string>
#include "poya.hpp"

using namespace std;

poya::poya() :Hero("poya kazhdom" , "Attacker" , 500 , 3 , "<< Did you see my bite? No? Well... you'll never see it... >>" , 2 , 4 , 5 )
{
}

void poya::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{

} 
    
void poya::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{

}
    
void poya::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{

}

void poya::choice_ability() 
{
    cout << "<< Pooya Kazhdom >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1) DAGGER (2 Energy)" << endl;
    cout << " 2) SCORPION (4 Energy)" << endl;
    cout << " 3) Special = SCORPION'S TAIL (5 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

poya::~poya()
{
}


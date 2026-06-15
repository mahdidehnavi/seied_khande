#include <iostream>
#include <string>
#include "amin.hpp"

using namespace std;

amin::amin() :Hero("Amin emini" , "Attacker" , 500 , 3 , "<< One.. Two.. Three.. BOOM... who's left? It doesn't matter >>"  , 3 , 3 , 4)
{
}

void amin::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
   
}
    
void amin::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}

void amin::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}

void amin::choice_ability() 
{
    cout << "<< Amin Emini >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1.LAST BULLET (3 Energy)" << endl;
    cout << " 2.FRIENDLY FIRE (3 Energy)" << endl;
    cout << " 3.Special = INSECURITY SCREAM (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }

}

amin::~amin()
{
}


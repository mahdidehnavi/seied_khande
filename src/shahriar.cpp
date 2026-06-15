#include <iostream>
#include <string>
#include "shahriar.hpp"

using namespace std;

shahriar::shahriar() :Hero("Mr shahriar" , "Joker" , 500 , 4 , "<< Good becomes bad... bad becomes good...\nWho am I? mr shahriar... repeat it out loud,learn... >>" , 2 , 4 , 4 )
{
}

void shahriar::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{

}

void shahriar::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{

}
    
void shahriar::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{

}
    
void shahriar::choice_ability() 
{
    cout << "<< Agha Shahriar >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1) MOCK (2 Energy)" << endl;
    cout << " 2) STUBBORN (4 Energy)" << endl;
    cout << " 3) Special = WORLD INVERSION (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

shahriar::~shahriar()
{
}



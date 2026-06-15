#include <iostream>
#include <string>
#include "dany_go.hpp"

using namespace std;

dany_go::dany_go() :Hero("Danny Golang" , "Defender" , 600 , 4 , "<< No one crosses this line! >>" , 2 , 4 , 4)
{
}

void dany_go::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}

void dany_go::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}

void dany_go::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}

void dany_go::choice_ability() 
{
    cout << "<< Dani Golang >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1) UTINE LOCK (2 Energy)" << endl;
    cout << " 2) ELEPHANT KILLER (4 Energy)" << endl;
    cout << " 3) Special = FAMILY SHELTER (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

dany_go::~dany_go()
{
}



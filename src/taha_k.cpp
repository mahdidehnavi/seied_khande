#include <iostream>
#include <string>
#include "taha_k.hpp"

using namespace std;

taha_k::taha_k() :Hero("Taha kochike" , "Healer" , 500 , 3 , "<< All in their place! This area is contaminated! >>" , 2 , 4 , 4)
{
}

void taha_k::ability1(int Energy) 
{
    cout << "\n   > Heal 40 HP to a random teammate & deal 40 damage to enemy" << endl;

}

void taha_k::ability2(int Energy) 
{
    cout << "\nability2 taha ko \n";
}

void taha_k::special_ablity(int Energy) 
{
    cout << "\nspecial ability taha ko\n";
}

void taha_k::choice_ability() 
{
    cout << "<< Taha Kuchik >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1) SHARP BLADE (2 Energy)" << endl;
    cout << " 2) BLOOD SERUM (4 energy)" << endl;
    cout << " 3) Special = COMPLETE QUARANTINE (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

taha_k::~taha_k()
{
}

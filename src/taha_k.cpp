#include <iostream>
#include <string>
#include "taha_k.hpp"

using namespace std;

taha_k::taha_k() :Hero("Taha kochike" , "Healer" , 500 , 3 , "<< All in their place! This area is contaminated! >>" , 2 , 4 , 4)
{
}

void taha_k::ability1(Hero* ptTeam[] , Hero* ptEnemy[]) 
{
    cout << "\n   > Heal 40 HP to a random teammate & deal 40 damage to enemy" << endl;
    int hp;
    int min_hp ;
    int min_player;
    for (int i = 0; i < 3; i++)
    {
        hp = ptTeam[i]->get_hp();
        if (min_hp >= hp)
        {
            min_hp = hp ;
            min_player = i ;
        }
        
    }
    ptTeam[min_player]->heal(20);
    
    int enemy;
    cout << "choose a player to damage(1-3): ";
    cin >> enemy;
    while(enemy < 0 || enemy > 3)
    {
        cout << "\nEnter correct number(1-3): ";
        cin >> enemy;
    }
    ptEnemy[enemy]->takedamage(30);

}

void taha_k::ability2(Hero* ptTeam[] , Hero* ptEnemy[]) 
{

}

void taha_k::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) 
{

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

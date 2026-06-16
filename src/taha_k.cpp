#include <iostream>
#include <string>
#include "taha_k.hpp"

using namespace std;

taha_k::taha_k() :Hero("Taha kochike" , "Healer" , 500 , 3 , "<< All in their place! This area is contaminated! >>" , 2 , 4 , 4)
{
}

void taha_k::ability1(Hero* ptTeam[] , Hero* ptEnemy[]) 
{
    cout << "\n> Heal 20 HP to a lowest teammate & deal 30 damage to enemy" << endl;
    int hp;
    int min_hp = 600;
    int min_player;
    for (int i = 0; i < 3; i++)
    {
        hp = ptTeam[i]->get_hp();
        if (min_hp >= hp && hp != 0)
        {
            min_hp = hp ;
            min_player = i ;
        }
        
    }
    ptTeam[min_player]->heal(20);
    
    int enemy;
    cout << "Select a target to deal 30 damage(1-3): ";
    cin >> enemy;
    while(enemy < 0 || enemy > 3 || !ptEnemy[enemy]->checkalive())
    {
        if(enemy < 0 || enemy > 3)
        {
            cout << "\nEnter correct number(1-3): ";
            cin >> enemy;
        }
        if(!ptEnemy[enemy]->checkalive())
        {
            cout << "\nSelect a living target: ";
            cin >> enemy;
        }
    }
    ptEnemy[enemy]->takedamage(30);

    cout << "\n20 HP restored to " << ptTeam[min_player]->get_name() << endl;
    cout << ptEnemy[enemy]->get_name() << "took 30 damage." << endl;
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

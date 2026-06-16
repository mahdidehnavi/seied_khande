#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "shahriar.hpp"

using namespace std;

shahriar::shahriar() :Hero("Mr Shahriar" , "Joker" , 500 , 4 , "<< Good becomes bad... bad becomes good...\nWho am I? mr shahriar... repeat it out loud,learn... >>" , 2 , 4 , 8 )
{
}

void shahriar::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nMr Shahriar Ability 1: MOCK" << endl;
    cout << "   > Deal 60 damage to target" << endl;
    cout << "   > 20% chance of miss" << endl;

    srand(static_cast<unsigned int>(time(0))) ;

    int enemy;
    cout << "Select a target to deal damage(1-3): ";
    cin >> enemy;
    while(enemy < 1 || enemy > 3 || !ptEnemy[enemy - 1]->checkalive())
    {
        if(enemy < 1 || enemy > 3)
        {
            cout << "\nEnter correct number(1-3): ";
            cin >> enemy;
        }
        if(!ptEnemy[enemy - 1]->checkalive())
        {
            cout << "\nSelect a living target: ";
            cin >> enemy;
        }
    }
    
    int randomN = rand() % 5 + 1;
    
    if(randomN == 1) //20%
    {
        cout << "Your shot missed. " << endl;
    }
    if(randomN >= 2 && randomN <= 5) //80%
    {
        ptEnemy[enemy - 1]->takedamage(60);
        cout << ptEnemy[enemy - 1]->get_name() << "took 30 damage." << endl;

    }
}


void shahriar::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nMr Shahriar Ability 2: STUBBORN" << endl;
    cout << "   > Deal 100 damage to random enemy (not the target)" << endl;

    

}


void shahriar::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nMr Shahriar Special Ability: WORLD INVERSION" << endl;
    cout << "   > For 2 turns, everything reverses:" << endl;
    cout << "   > Damage to enemy becomes healing" << endl;
    cout << "   > Healing to teammate becomes damage" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;
    cout << "   > WARNING: This can destroy your own team!" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;



}
    
void shahriar::choice_ability() 
{
    cout << "<< Agha Shahriar >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ MOCK (2 Energy)" << endl;
    cout << " 2)⚔️ STUBBORN (4 Energy)" << endl;
    cout << " 3)✨ Special = WORLD INVERSION (8 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

shahriar::~shahriar()
{
}



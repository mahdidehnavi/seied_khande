#include <iostream>
#include <string>
#include "poya.hpp"

using namespace std;

poya::poya() :Hero("poya Kazhdom" , "Attacker" , 500 , 3 , "<< Did you see my bite? No? Well... you'll never see it... >>" , 2 , 4 , 5 )
{
}

void poya::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\npoya Kazhdom Ability 1: DAGGER " << endl;
    cout << "   > Deal 40 damage to target & activate scorpions if exists" << endl;


} 
    
void poya::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\npoya Kazhdom Ability 2: SCORPION" << endl;
    cout << "   > Lock a scorpion on target, deals 20 damage each turn" << endl;
    cout << "   > If dagger calls them, each scorpion deals 60 damage" << endl;


}
    
void poya::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\npoya Kazhdom Special Ability: SCORPION'S TAIL" << endl;
    cout << "   > Pooya hides (only takes area damage) for 3 turns" << endl;
    cout << "   > After 3 turns, deals 450 damage to random enemy & returns" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;


    cout << "\n🔥" << Angry_massage << "🔥" << endl;


}

void poya::choice_ability() 
{
    cout << "<< Pooya Kazhdom >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ DAGGER (2 Energy)" << endl;
    cout << " 2)⚔️ SCORPION (4 Energy)" << endl;
    cout << " 3)✨ Special = SCORPION'S TAIL (5 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

poya::~poya()
{
}


#include <iostream>
#include <string>
#include "amin.hpp"

using namespace std;

amin::amin() :Hero("Amin Emeni" , "Attacker" , 500 , 3 , "<< One.. Two.. Three.. BOOM... who's left? It doesn't matter >>"  , 3 , 3 , 4)
{
}

void amin::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Ability 1: LAST BULLET" << endl;
    cout << "   > Deal 55 damage to enemy" << endl;
    cout << "   > If it kills the enemy, damage doubles (110)" << endl;




}
    
void amin::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Ability 2: FRIENDLY FIRE" << endl;
    cout << "   > Take 25 HP from a teammate & heal self by 75 HP" << endl;




}

void amin::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Special Ability: INSECURITY SCREAM" << endl;
    cout << "   > Deal 250 damage to random enemy & 30 damage to 2 teammates" << endl;
    cout << "   > Cooldown: Once every 3 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;


}

void amin::choice_ability() 
{
    cout << "<< Amin Emeni >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ LAST BULLET (3 Energy)" << endl;
    cout << " 2)⚔️ FRIENDLY FIRE (3 Energy)" << endl;
    cout << " 3)✨ Special = INSECURITY SCREAM (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }

}

amin::~amin()
{
}


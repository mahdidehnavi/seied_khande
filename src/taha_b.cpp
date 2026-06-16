#include <iostream>
#include <string>
#include "taha_b.hpp"

using namespace std;

taha_b::taha_b() :Hero("Taha Bozorge" , "Attacker" , 500 , 4 , "<< This one was for my little brother... Now it's your turn... >>" , 3 , 4 , 3)
{
}

void taha_b::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nTaha Bozorge Ability 1: BARRAGE" << endl;
    cout << "   > Deal 30 damage to all enemies" << endl;

    

}

void taha_b::ability2(Hero* ptTeam[] , Hero* ptEnemy[])    
{
    cout << "\nTaha Bozorge Ability 2: X-RAY" << endl;
    cout << "   > Deal 90 damage to target & become hidden for 1 turn" << endl;



}
    
void taha_b::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nTaha Bozorge Special Ability: BROTHER'S REVENGE" << endl;
    cout << "   > Mark a random enemy, next turn takes 360 damage" << endl;
    cout << "   > If enemy HP < 360: dies, if HP > 360: takes 200 damage" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;



}

void taha_b::choice_ability() 
{
    cout << "<< Taha Bozorge >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ BARRAGE (3 Energy)" << endl;
    cout << " 2)⚔️ X-RAY (4 Energy)" << endl;
    cout << " 3)✨ Special = BROTHER'S REVENGE (3 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

    
taha_b::~taha_b()
{
}



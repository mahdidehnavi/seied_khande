#include <iostream>
#include <string>
#include "Dr_white.hpp"

using namespace std;

Dr_white::Dr_white() :Hero("Doctor White" , "Healer" , 550 , 4 , "<< Bring it to the table... it'll survive if you're lucky. >>" , 3, 4, 4)
{
}

void Dr_white::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDoctor White Ability 1: ASPIRIN" << endl;
    cout << "   > Heal 40 HP to a random teammate & deal 40 damage to enemy" << endl;




} 
    
void Dr_white::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDoctor White Ability 2: DOPING" << endl;
    cout << "   > A teammate deals 20% more damage for 2 rounds" << endl;





}
    
void Dr_white::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDoctor White Special Ability: OPERATING ROOM OPERATIONS - energy = 4" << endl;
    cout << "   > Revive a dead teammate (200 HP) & remove all negative effects" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;


}
    
void Dr_white::choice_ability() 
{
    cout << "<< Doctor White >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ ASPIRIN (3 Energy)" << endl;
    cout << " 2)⚔️ DOPING (4 Energy)" << endl;
    cout << " 3)✨ Special = OPERATING ROOM OPERATIONS (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

Dr_white::~Dr_white()
{
}

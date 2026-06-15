#include <iostream>
#include <string>
#include "Dr_white.hpp"

using namespace std;

Dr_white::Dr_white() :Hero("Doctor White" , "Healer" , 550 , 4 , "<< Bring it to the table... it'll survive if you're lucky. >>" , 3, 4, 4)
{
}

void Dr_white::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
} 
    
void Dr_white::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    
}
    
void Dr_white::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{

}
    
void Dr_white::choice_ability() 
{
    cout << "<< Doctor White >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1) ASPIRIN (3 Energy)" << endl;
    cout << " 2) DOPING (4 Energy)" << endl;
    cout << " 3) Special = OPERATING ROOM OPERATIONS (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

Dr_white::~Dr_white()
{
}

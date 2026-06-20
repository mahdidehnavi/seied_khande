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

    int round ;
    do
    {
        round = 1 + rand() % 3 ;
    } 
    while (!ptEnemy[round - 1]->checkalive());
    ptTeam[round - 1]->heal(40);


    bool checkTarget = false;

    for(int i = 0; i < 3; i++)
    {
        if(ptEnemy[i]->checkalive()) 
        checkTarget = true;
    }

    if(checkTarget)
    {
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
                if(!ptEnemy[enemy -1]->checkalive())
                {
                    cout << "\nSelect a living target: ";
                    cin >> enemy;
                }
            }
            ptEnemy[enemy - 1]->takedamage(40);
        
        
    } 
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
        
    }


} 
    

void Dr_white::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDoctor White Ability 2: DOPING" << endl;
    cout << "   > A teammate deals 20% more damage for 2 rounds" << endl;
    
    cout << "pick a number (1-3): ";
    cin >> choose ;
    while(choose < 1 || choose > 3 || !ptTeam[choose - 1]->checkalive())
    {
        if(choose < 1 || choose > 3)
        {
            cout << "\nEnter correct number(1-3): ";
            cin >> choose;
        }
        if(!ptTeam[choose -1]->checkalive())
        {
            cout << "\nSelect a living target: ";
            cin >> choose;
        }
    }
    ptTeam[choose - 1]->set_doping(true);

    check2 = true;

    rnd_end = 2;

    cout << ptTeam[choose - 1]->get_name() << " is now DOPED!" << endl;
    cout << "   > Will deal 20% more damage for the next 2 rounds" << endl;
}


void Dr_white::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDoctor White Special Ability: OPERATING ROOM OPERATIONS - energy = 4" << endl;
    cout << "   > Revive a dead teammate (200 HP) & remove all negative effects" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;

    int hp ;
    int dead = 4 ;

    for (int i = 0; i < 3; i++)
    {
        hp = ptTeam[i]->get_hp();
        if (hp == 0 && ptTeam[i] != this)
        {
            dead = i ;
            break;
        }
        
    }
    if (dead != 4)
    {
        ptTeam[dead]->set_hp(200);

        cout << "\n" << ptTeam[dead]->get_name() << " revived with 200 HP!" << endl;
    }
    else
    {
        cout << "\n No dead teammate to revive!" << endl;
    }
    
    to_get_rage = rageThreshold;

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

void Dr_white::after_rnd(Hero* ptTeam[] , Hero* ptEnemy[])
{
    ptTeam[choose - 1]->set_doping(false);
}


Dr_white::~Dr_white()
{
}

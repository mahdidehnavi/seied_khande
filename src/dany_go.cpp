#include <iostream>
#include <string>
#include "dany_go.hpp"

using namespace std;

dany_go::dany_go() :Hero("Danny Golang" , "Defender" , 600 , 4 , "<< No one crosses this line! >>" , 2 , 4 , 4)
{
}

void dany_go::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDanny Golang Ability 1: GOROUTINE LOCK" << endl;
    cout << "   > Deal 20 damage to an enemy" << endl;
    cout << "   > If repeated on same enemy, damage multiplies by 1.6x" << endl;

    int enemy;
    cout << "Enter correct number (1-3) ";
    cin >> enemy;
    
    while(enemy < 1 || enemy > 3 || !ptEnemy[enemy - 1]->checkalive())
    {
        if(enemy < 1 || enemy > 3)
        {
            cout << "Enter correct number (1-3): ";
            cin >> enemy;
        }
        if(!ptEnemy[enemy - 1]->checkalive())
        {
            cout << "Select a living target (1-3): ";
            cin >> enemy;
        }
    }

    int damage = 20;
    
    if (ptEnemy[enemy - 1]->get_ghofly())
    {
        damage = 20 + (20 * 60 / 100);  
        cout << "\n Repeated on " << ptEnemy[enemy - 1]->get_name() << "! Damage = 32 (1.6x)!" << endl;
    }
    else
    {
        cout << "\n" << ptEnemy[enemy - 1]->get_name() << " took 20 damage!" << endl;
        ptEnemy[enemy - 1]->set_ghofly(2);
    }
    
    ptEnemy[enemy - 1]->takedamage(damage);
    cout << "   > Remaining HP: " << ptEnemy[enemy - 1]->get_hp() << endl;

    
}

void dany_go::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDanny Golang Ability 2: ELEPHANT KILLER" << endl;
    cout << "   > Deal 50 damage to target & 50 damage to enemy with highest HP" << endl;

    int enemy;
    cout << "Enter correct number (1-3) ";
    cin >> enemy;
    
    while(enemy < 1 || enemy > 3 || !ptEnemy[enemy - 1]->checkalive())
    {
        if(enemy < 1 || enemy > 3)
        {
            cout << "Enter correct number (1-3): ";
            cin >> enemy;
        }
        if(!ptEnemy[enemy - 1]->checkalive())
        {
            cout << "Select a living target (1-3): ";
            cin >> enemy;
        }
    }
    
    ptEnemy[enemy - 1]->takedamage(50);
    cout << "💥 " << ptEnemy[enemy - 1]->get_name() << " took 50 damage!" << endl;
    
    int k = 0;
    for (int i = 1; i < 3; i++)
    {
        if (ptEnemy[i]->get_hp() > ptEnemy[k]->get_hp())
        {
            k = i;
        }
    }
    
    if (k != enemy - 1)
    {
        ptEnemy[k]->takedamage(50);
        cout << ptEnemy[k]->get_name() << " (highest HP) took 50 damage!" << endl;
    }
    else
    {
        cout << " Target already had the highest HP! Already took damage." << endl;
    }
}

void dany_go::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDanny Golang Special Ability: FAMILY SHELTER" << endl;
    cout << "   > Give 250 HP shield to lowest HP teammate for 2 turns" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;

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
     rnd_end = 2;

    ptTeam[min_player]->set_shielt(250) ;

    
}

void dany_go::choice_ability() 
{
    cout << "<< Dani Golang >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ UTINE LOCK (2 Energy)" << endl;
    cout << " 2)⚔️ ELEPHANT KILLER (4 Energy)" << endl;
    cout << " 3)✨ Special = FAMILY SHELTER (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}

dany_go::~dany_go()
{
}



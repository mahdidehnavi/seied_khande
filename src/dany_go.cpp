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

    bool checkTarget = false;

    for(int i = 0; i < 3; i++)
    {
        if(ptEnemy[i]->checkalive()) 
        checkTarget = true;
    }

    if(checkTarget)
    {
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
    
        int damage = ptEnemy[enemy - 1]->get_ghofly();
        
        if (damage != 0)
        {
            damage = damage * 1.6;  
    
            cout << "\n Repeated on " << ptEnemy[enemy - 1]->get_name() << "! Damage = " << damage << endl;
        }
        else
        {
            ptEnemy[enemy - 1]->set_ghofly(damage);
        }
    
        ptEnemy[enemy - 1]->takedamage(damage);
        cout << "   > Remaining HP: " << ptEnemy[enemy - 1]->get_hp() << endl;
        
    } 
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
        
    }
}


void dany_go::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nDanny Golang Ability 2: ELEPHANT KILLER" << endl;
    cout << "   > Deal 50 damage to target & 50 damage to enemy with highest HP" << endl;

    bool checkTarget = false;

    for(int i = 0; i < 3; i++)
    {
        if(ptEnemy[i]->checkalive()) 
        checkTarget = true;
    }

    if(checkTarget)
    {
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
        
        int k = 0;
        for (int i = 1; i < 3; i++)
        {
            if (ptEnemy[i]->get_hp() > ptEnemy[k]->get_hp())
            {
                k = i;
            }
        }
        
        cout << endl << ptEnemy[k]->get_name() << " has the most Hp"; 

        ptEnemy[k]->takedamage(50);
    } 
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
        
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
    for (int i = 0; i < 3; i++)
    {
        hp = ptTeam[i]->get_hp();
        if (min_hp >= hp && hp != 0)
        {
            min_hp = hp ;
            min_player = i ;
        }
        
    }
     
    check2 = true;
    rnd_end = 2;

    ptTeam[min_player]->set_shield(250);

    to_get_rage = rageThreshold;
   
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


void dany_go::after_rnd(Hero* ptTeam[] , Hero* ptEnemy[])
{
    ptTeam[min_player]->set_shield(0);
   
}

dany_go::~dany_go()
{
}



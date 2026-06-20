#include <iostream>
#include <string>
#include "taha_k.hpp"

using namespace std;

taha_k::taha_k() :Hero("Taha kochike" , "Healer" , 500 , 3 , "<< All in their place! This area is contaminated! >>" , 2 , 4 , 4)
{
}

void taha_k::ability1(Hero* ptTeam[] , Hero* ptEnemy[]) 
{
    cout << "\nTaha Kochike Ability 1: SHARP BLADE" << endl;
    cout << "   > Heal 20 HP to lowest HP teammate & deal 30 damage to enemy" << endl;
    
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
    

    bool checkTarget = false;

    for(int i = 0; i < 3; i++)
    {
        if(ptEnemy[i]->checkalive()) 
        checkTarget = true;
    }

    if(checkTarget)
    {
        int enemy;
        cout << "Select a target to deal 30 damage(1-3): ";
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
        ptEnemy[enemy - 1]->takedamage(30);
            
    } 
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
        
    }
        
}


void taha_k::ability2(Hero* ptTeam[] , Hero* ptEnemy[]) 
{
    cout << "\nTaha Kochike Ability 2: BLOOD SERUM" << endl;
    cout << "   > Heal a teammate for 40 HP for 2 rounds" << endl;
    
    round = rand() % 3 ;
    
    while(!ptEnemy[round]->checkalive())
    {
        round = rand() % 3 ;
    }
    
    ptTeam[round]->heal(40);
    
    check2 = true ;

    rnd_end = 1;
    
}


void taha_k::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) 
{
    cout << "\nTaha Kochike Special Ability: COMPLETE QUARANTINE" << endl;
    cout << "   > Heal the lowest HP teammate by 200 HP" << endl;
    cout << "   > Cooldown: Once every 3 rounds" << endl;

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
    ptTeam[min_player]->heal(200);


    to_get_rage = rageThreshold;

}


void taha_k::choice_ability() 
{
    cout << "<< Taha Kochike >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ SHARP BLADE (2 Energy)" << endl;
    cout << " 2)⚔️ BLOOD SERUM (4 energy)" << endl;
    cout << " 3)✨ Special = COMPLETE QUARANTINE (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }
}


void taha_k::after_rnd(Hero* ptTeam[] , Hero* ptEnemy[])
{

    if(ptTeam[round]->checkalive())
    {
        ptTeam[round]->heal(40);
    }

}


taha_k::~taha_k()
{
}

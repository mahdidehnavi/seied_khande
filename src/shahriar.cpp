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
        }
       
        
    }     
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
    }    
}


void shahriar::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nMr Shahriar Ability 2: STUBBORN" << endl;
    cout << "   > Deal 100 damage to random enemy (not the target)" << endl;

    int enemy;
    cout << "Select a target(1-3): ";
    cin >> enemy;
    while(enemy < 1 || enemy > 3)
    {
        if(enemy < 1 || enemy > 3)
        {
            cout << "\nEnter correct number(1-3): ";
            cin >> enemy;
        }
    }

    bool checkTarget = false;

    for(int i = 0; i < 3; i++)
    {
        if(ptEnemy[i]->checkalive() && (i + 1) != enemy) 
        checkTarget = true;
    }

    if(checkTarget)
    {
        int round;
        round = 1 + rand() % 3 ;
            
        while(!ptEnemy[round - 1]->checkalive() || round == enemy )
        {
            round = 1 + rand() % 3 ;
        }
    
        ptEnemy[round - 1]->takedamage(100);
    
        
    }     
    else 
    {
        cout << "\n❌ No valid targets available." << endl;
    }    
    

}


void shahriar::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{

    cout << "\nAgha Shahriar Special Ability: WORLD REVERSAL" << endl;
    cout << "   > For 2 turns, everything reverses:" << endl;
    cout << "   > Damage to enemy becomes healing" << endl;
    cout << "   > Healing to teammate becomes damage" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;
    cout << "   > WARNING: This can destroy your own team!" << endl;
    
    cout << "\n🔥" << Angry_massage << "🔥" << endl;

    joker = true;
    rnd_end = 2;

    to_get_rage = rageThreshold;
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
    } 
    else 
    {
        cout << "❌ you can not use ❌" << endl;
    }
}

shahriar::~shahriar()
{
}



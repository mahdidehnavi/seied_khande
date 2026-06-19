#include <iostream>
#include <string>
#include "poya.hpp"

using namespace std;

poya::poya() :Hero("poya Kazhdom" , "Attacker" , 500 , 4 , "<< Did you see my bite? No? Well... you'll never see it... >>" , 2 , 4 , 5 )
{
}

void poya::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{

    if(!check2)
    {
            cout << "\npoya Kazhdom Ability 1: DAGGER " << endl;
            cout << "   > Deal 40 damage to target & activate scorpions if exists" << endl;
        
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
            
                ptEnemy[enemy - 1]->takedamage(40);
                cout << ptEnemy[enemy - 1]->get_name() << " took 40 damage." << endl;
                
                
                if (check)
                {
                    ptEnemy[enemy - 1]->takedamage(60);
                    cout << ptEnemy[enemy - 1]->get_name() << " took 60 damage(for SCORPION & DAGGER)." << endl;
        
                    check = false;
                }
               
            }     
            else {
                cout << "\n❌ No valid targets available." << endl;
            }    
        
    }
    else 
    {
        cout << endl << name << " is hidden." << endl;
    }
    

} 
    
void poya::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    if(!check2)
    {
        
        static int enemy;
        if(!check)
        {
            cout << "\npoya Kazhdom Ability 2: SCORPION" << endl;
            cout << "   > Lock a scorpion on target, deals 20 damage each turn" << endl;
            cout << "   > If dagger calls them, each scorpion deals 60 damage" << endl;
        
            bool checkTarget = false;
    
            for(int i = 0; i < 3; i++)
            {   
                if(ptEnemy[i]->checkalive()) 
                checkTarget = true;
            }
    
            if(checkTarget)
            {
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
        
                ptEnemy[enemy - 1]->takedamage(20);
                cout << ptEnemy[enemy - 1]->get_name() << " will take 20 damage every hand." << endl;
                cout << ptEnemy[enemy - 1]->get_name() << " took 20 damage." << endl;
           
            }     
            else {
                cout << "\n❌ No valid targets available." << endl;
            }    
            
        }
        else
        {
            if(ptEnemy[enemy - 1]->get_hp() != 0)
            {
                ptEnemy[enemy - 1]->takedamage(20);
                cout << ptEnemy[enemy - 1]->get_name() << " took 20 damage." << endl;
    
            }
    
        }
    }
    else 
    {
        cout << endl << name << " is hidden." << endl;
    }
    

}
    
void poya::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{

    
    cout << "\npoya Kazhdom Special Ability: SCORPION'S TAIL" << endl;
    cout << "   > Pooya hides (only takes area damage) for 3 turns" << endl;
    cout << "   > After 3 turns, deals 450 damage to random enemy & returns" << endl;
    cout << "   > Cooldown: Once every 4 rounds" << endl;
    
    cout << "\n🔥" << Angry_massage << "🔥" << endl;
    
    cout << "\npoya Kazhdom is hidden for 3 round." << endl;
    
    check2 = true;

    rnd_end = 3;

    to_get_rage = rageThreshold;
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

void poya::after_rnd(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << endl << name << " is no langerr hidden." << endl;
    
    int round = rand() % 3 ;
    
    while(!ptEnemy[round]->checkalive())
    {
        round = rand() % 3 ;
    }
    ptEnemy[round]->takedamage(450);
}

void poya::takedamage(const int dmg)
{
    if(!check2)
    {
        Hp -= dmg;
        if(Hp < 0) Hp = 0;
    }
    else {
        cout << endl << name << " is hidden." << endl;
    }
}


poya::~poya()
{
}


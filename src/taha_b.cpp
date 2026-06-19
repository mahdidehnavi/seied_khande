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

    for(int i = 0 ; i < 3 ; i++)
    {
        ptEnemy[i]->takedamage(30);
    }
    
    cout << "\nAll enemy players took 30 damage." << endl;

}

void taha_b::ability2(Hero* ptTeam[] , Hero* ptEnemy[])    
{
    
    cout << "\nTaha Bozorge Ability 2: X-RAY" << endl;
    cout << "   > Deal 90 damage to target & become hidden for 1 turn" << endl;


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
        ptEnemy[enemy - 1]->takedamage(90);

        check2 = true;

        rnd = 1;

        cout << "\nTaha Bozorge is hidden for a round." << endl;
       
    }    
    else {
        cout << "\n❌ No valid targets available." << endl;
    }

   



}
    
void taha_b::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    static int round;   
    if(!check2)
    {
        cout << "\nTaha Bozorge Special Ability: BROTHER'S REVENGE" << endl;
        cout << "   > Mark a random enemy, next turn takes 360 damage" << endl;
        cout << "   > If enemy HP < 360: dies, if HP > 360: takes 200 damage" << endl;
        cout << "   > Cooldown: Once every 4 rounds" << endl;
    
        cout << "\n🔥" << Angry_massage << "🔥" << endl;

        bool checkTarget = false;

        for(int i = 0; i < 3; i++)
        {
            if(ptEnemy[i]->checkalive()) 
            checkTarget = true;
        }

        if(checkTarget)
        {
            round = rand() % 3 ;
            
            while(!ptEnemy[round]->checkalive())
            {
                round = rand() % 3 ;
            }
    
            cout << "\nIt well be done in the next round." << endl;
    
            check2 = true;
        
        }    
        else {
            cout << "\n❌ No valid targets available." << endl;
        }
    }
    else
    {
        if(ptEnemy[round]->get_hp() > 360)
        {
            ptTeam[round]->takedamage(200);
            cout << ptEnemy[round]->get_name() << "took 200 damage." << endl;
            
        } 
        else if(ptEnemy[round]->get_hp() != 0)
        {
            ptTeam[round]->takedamage(360);
            cout << ptEnemy[round]->get_name() << "took " << ptEnemy[round]->get_hp() << " damage." << endl;

        }

        check2 = false;
    }
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

void taha_b::takedamage(const int dmg)
{
    if(!check)
    {
        Hp -= dmg;
        if(Hp < 0) Hp = 0;
    }
    else {
        cout << endl << name << " is hidden." << endl;
    }
}


taha_b::~taha_b()
{
}



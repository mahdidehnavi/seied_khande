#include <iostream>
#include <string>
#include "amin.hpp"

using namespace std;

amin::amin() :Hero("Amin Emeni" , "Attacker" , 500 , 3 , "<< One.. Two.. Three.. BOOM... who's left? It doesn't matter >>"  , 3 , 3 , 4)
{
}

void amin::ability1(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Ability 1: LAST BULLET" << endl;
    cout << "   > Deal 55 damage to enemy" << endl;
    cout << "   > If it kills the enemy, damage doubles (110)" << endl;
    int enemy;
    cout << "Select a target (1-3): ";
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
    
    int targetHp = ptEnemy[enemy - 1]->get_hp();
    int damage;
    
    if (targetHp <= 55)  
    {
        damage = 110;  
        cout << "\n" << ptEnemy[enemy - 1]->get_name() << " will die! Damage DOUBLED to 110!" << endl;
    }
    else
    {
        damage = 55;  
        cout << "\n Dealing 55 damage to " << ptEnemy[enemy - 1]->get_name() << endl;
    }
    
    ptEnemy[enemy - 1]->takedamage(damage);
    
    cout << ptEnemy[enemy - 1]->get_name() << " took " << damage << " damage!" << endl;
    cout << "   > Remaining HP: " << ptEnemy[enemy - 1]->get_hp() << endl;



}

    
void amin::ability2(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Ability 2: FRIENDLY FIRE" << endl;
    cout << "   > Take 25 HP from a teammate & heal self by 75 HP" << endl;

    int teammate;
    cout << "Select a teammate to take 25 HP from (1-3): ";
    cin >> teammate;
    
    while(teammate < 1 || teammate > 3 || !ptTeam[teammate - 1]->checkalive())
    {
        if(teammate < 1 || teammate > 3)
        {
            cout << "Enter correct number (1-3): ";
            cin >> teammate;
        }
        else if(!ptTeam[teammate - 1]->checkalive())
        {
            cout << "Select a living teammate (1-3): ";
            cin >> teammate;
        }
    }
    if (ptTeam[teammate - 1] == this)
    {
        cout << "\n You chose yourself!" << endl;
        cout << "   > You lose 25 HP but heal 75 HP (net +50 HP)" << endl;
    }
    
    ptTeam[teammate - 1]->takedamage(25);
    this->heal(75);
    cout << "\n💔 " << ptTeam[teammate - 1]->get_name() << " lost 25 HP!" << endl;
    cout << "💚 " << this->get_name() << " healed 75 HP!" << endl;
    cout << "   > Current HP: " << this->get_hp() << endl;


}

void amin::special_ablity(Hero* ptTeam[] , Hero* ptEnemy[])
{
    cout << "\nAmin Emeni Special Ability: INSECURITY SCREAM" << endl;
    cout << "   > Deal 250 damage to random enemy & 30 damage to 2 teammates" << endl;
    cout << "   > Cooldown: Once every 3 rounds" << endl;

    cout << "\n🔥" << Angry_massage << "🔥" << endl;

    int round ;
    round = 1 + rand() % 3 ;
    int enemy = round ; 

    while(!ptEnemy[enemy]->checkalive())
    {
        enemy = rand() % 3;
    }

    ptEnemy[enemy - 1]->takedamage(250);
    cout << "\n💥 " << ptEnemy[enemy]->get_name() << " took 250 damage!" << endl;


    for (int i = 0; i < 3; i++)
    {
        if (ptTeam[i] != this)
        {
            ptTeam[i]->takedamage(30);
            cout << "💔 " << ptTeam[i]->get_name() << " took 30 damage!" << endl;
        }
    }

}

void amin::choice_ability() 
{
    cout << "<< Amin Emeni >>";
    cout << "   ❤️ HP: " << Hp;
    if(!checkalive()) {
        cout << "     Dead ☠️ ";
    }
    cout << endl;
    cout << " 1)⚔️ LAST BULLET (3 Energy)" << endl;
    cout << " 2)⚔️ FRIENDLY FIRE (3 Energy)" << endl;
    cout << " 3)✨ Special = INSECURITY SCREAM (4 Energy)";
    if(checkRage()){
        cout << "✅ you can use ✅" << endl;
    } else {
        cout << "❌ you can not use ❌" << endl;
    }

}

amin::~amin()
{
}


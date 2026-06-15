#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "controller.hpp"

#include "Dr_white.hpp"
#include "taha_k.hpp"
#include "dany_go.hpp"
#include "amin.hpp"
#include "taha_b.hpp"
#include "poya.hpp"
#include "shahriar.hpp"



controller::controller(/* args */)
{
}



void controller::show_hero() const
{
    cout << "\n                       heroes                            \n";
    cout << "┌────┬─────────────────────┬──────────┬──────┬\n";
    cout << "│ No │ Name                │ Role     │ HP   │\n";
    cout << "├────┼─────────────────────┼──────────┼──────┤\n";
    cout << "│ 1  │ Doctor White        │ Healer   │ 550  │\n";
    cout << "│ 2  │ Taha Kuchik         │ Healer   │ 500  │\n";
    cout << "│ 3  │ Dani Golang         │ Defender │ 600  │\n";
    cout << "│ 4  │ Amin Emini          │ Attacker │ 500  │\n";
    cout << "│ 5  │ Taha Bozorg         │ Attacker │ 500  │\n";
    cout << "│ 6  │ Pooya Kazdum        │ Attacker │ 550  │\n";
    cout << "│ 7  │ Agha Shahriar       │ Joker    │ 500  │\n";
    cout << "└────┴─────────────────────┴──────────┴──────┘\n";

}






void controller::choice_heros(std::vector<int>& team , const std::string& teamName , Hero* ptrteam[])
{
    int k = 0;
    while (k < 3)
    {
        cout << "Enter a number for choice hero (1-7): ";
        
        int choice;
        cin >> choice;
        
        bool Selected = false;
        for (int i = 0; i < team.size(); i++)
        {
            if (team[i] == choice)
            {
                Selected = true;
                cout << "This hero is already selected! Choose another one.\n";
                break;
            }
        }
        
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid number! Please enter a number between 1-7.\n";
            continue;
        }
        
        if (!Selected)
        {
            switch (choice)
            {
                case 1:
                    team.push_back(1);
                    ptrteam[k] = new Dr_white();
                    cout << "Doctor White added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 2:
                    team.push_back(2);
                    ptrteam[k] = new taha_k();
                    cout << "Taha Kuchik added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 3:
                    team.push_back(3);
                    ptrteam[k] = new dany_go();
                    cout << "Dani Golang added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 4:
                    team.push_back(4);
                    ptrteam[k] = new amin();
                    cout << "Amin Emini added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 5:
                    team.push_back(5);
                    ptrteam[k] = new taha_b();
                    cout << "Taha Bozorg added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 6:
                    team.push_back(6);
                    ptrteam[k] = new poya();
                    cout << "Pooya Kazdum added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 7:
                    team.push_back(7);
                    ptrteam[k] = new shahriar();
                    cout << "Agha Shahriar added to " << teamName << ".\n";
                    k++;
                    break;
            }
        }
    }
    
    cout << "\n" << teamName << " heroes: \n";
    for (int i = 0; i < team.size(); i++)
    {
        if (team[i]== 1)
        {
            cout << "Doctor White" << endl;
        }
        else if (team[i]== 2)
        {
            cout << "Taha Kuchik" << endl;
        }        
        else if (team[i]== 3)
        {
            cout << "Dani Golang" << endl;
        }        
        else if (team[i]== 4)
        {
            cout << "Amin Emini" << endl;
        }        
        else if (team[i]== 5)
        {
            cout << "Taha Bozorg" << endl;
        }        
        else if (team[i]== 6)
        {
            cout << "Pooya Kazdum" << endl;
        }        
        else if (team[i]== 7)
        {
            cout << "Agha Shahriar" << endl;
        }
    }
    cout << endl;
}

void controller::Enemy_Ability(std::vector<int>& team , Hero* ptrteam[])
{
    for (int i = 0; i < team.size(); i++)
    {
        if (team[i]== 1)
        {
            cout << "\t\t\t" << i+1 << ".Doctor White  HP : " << ptrteam[i]->get_hp() << endl;
        }
        else if (team[i]== 2)
        {
            cout << "\t\t\t" << i+1 << ".Taha Kuchik  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 3)
        {
            cout << "\t\t\t" << i+1 << ".Dani Golang  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 4)
        {
            cout << "\t\t\t" << i+1 << ".Amin Emini  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 5)
        {
            cout << "\t\t\t" << i+1 << ".Taha Bozorg  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 6)
        {
            cout << "\t\t\t" << i+1 << ".Pooya Kazdum  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 7)
        {
            cout << "\t\t\t" << i+1 << ".Agha Shahriar  HP : " << ptrteam[i]->get_hp() << endl;
        }
    }
    cout << endl;
}




void controller::start_action(std::vector<int>& team, const std::string& teamName)
{
    cout << "name team :" << teamName << endl ;
    for (int i = 0; i < team.size(); i++)
    {
        if (team[i] == 1)  
        {
            cout << "\n========================================" << endl;
            cout << "Doctor White - Role: Healer" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: ASPIRIN - energy = 3" << endl;
            cout << "   > Heal 40 HP to a random teammate & deal 40 damage to enemy" << endl;
            cout << "Ability 2: DOPING - energy = 4" << endl;
            cout << "   > A teammate deals 20% more damage for 2 rounds" << endl;
            cout << "Special Ability: OPERATING ROOM OPERATIONS - energy = 4" << endl;
            cout << "   > Quote: \"Bring him on the table... he'll live if he's lucky\"" << endl;
            cout << "   > Revive a dead teammate (200 HP) & remove all negative effects" << endl;
            cout << "   > Cooldown: Once every 4 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;
        }
        else if (team[i] == 2)  
        {
            cout << "\n========================================" << endl;
            cout << "Taha Kuchik - Role: Healer" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: SHARP BLADE - energy = 2" << endl;
            cout << "   > Heal 20 HP to lowest HP teammate & deal 30 damage to enemy" << endl;
            cout << "Ability 2: BLOOD SERUM - energy = 4" << endl;
            cout << "   > Heal a teammate for 40 HP for 2 rounds" << endl;
            cout << "Special Ability: COMPLETE QUARANTINE - energy = 4" << endl;
            cout << "   > Quote: \"Everyone stay in your place! This area is contaminated!\"" << endl;
            cout << "   > Heal the lowest HP teammate by 200 HP" << endl;
            cout << "   > Cooldown: Once every 3 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
        else if (team[i] == 3)  
        {
            cout << "\n========================================" << endl;
            cout << "Dani Golang - Role: Defender" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: GOROUTINE LOCK - energy = 2" << endl;
            cout << "   > Deal 20 damage to an enemy" << endl;
            cout << "   > If repeated on same enemy, damage multiplies by 1.6x" << endl;
            cout << "Ability 2: ELEPHANT KILLER - energy = 4" << endl;
            cout << "   > Deal 50 damage to target & 50 damage to enemy with highest HP" << endl;
            cout << "Special Ability: FAMILY SHELTER - energy = 4" << endl;
            cout << "   > Quote: \"No one passes this line!\"" << endl;
            cout << "   > Give 250 HP shield to lowest HP teammate for 2 turns" << endl;
            cout << "   > Cooldown: Once every 4 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
        else if (team[i] == 4)  
        {
            cout << "\n========================================" << endl;
            cout << "Amin Emini - Role: Attacker" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: LAST BULLET - energy = 3" << endl;
            cout << "   > Deal 55 damage to enemy" << endl;
            cout << "   > If it kills the enemy, damage doubles (110)" << endl;
            cout << "Ability 2: FRIENDLY FIRE - energy = 3" << endl;
            cout << "   > Take 25 HP from a teammate & heal self by 75 HP" << endl;
            cout << "Special Ability: INSECURITY SCREAM - energy = 4" << endl;
            cout << "   > Quote: \"One... two... three... boom... who's left? Doesn't matter...\"" << endl;
            cout << "   > Deal 250 damage to random enemy & 30 damage to 2 teammates" << endl;
            cout << "   > Cooldown: Once every 3 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
        else if (team[i] == 5)  
        {
            cout << "\n========================================" << endl;
            cout << "Taha Bozorg - Role: Attacker" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: BARRAGE - energy = 3" << endl;
            cout << "   > Deal 30 damage to all enemies" << endl;
            cout << "Ability 2: X-RAY - energy = 4" << endl;
            cout << "   > Deal 90 damage to target & become hidden for 1 turn" << endl;
            cout << "Special Ability: BROTHER'S REVENGE - energy = 3" << endl;
            cout << "   > Quote: \"This one was for my little brother... now it's your turn...\"" << endl;
            cout << "   > Mark a random enemy, next turn takes 360 damage" << endl;
            cout << "   > If enemy HP < 360: dies, if HP > 360: takes 200 damage" << endl;
            cout << "   > Cooldown: Once every 4 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
        else if (team[i] == 6)  
        {
            cout << "\n========================================" << endl;
            cout << "Pooya Kazdum - Role: Attacker" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: DAGGER - energy = 2" << endl;
            cout << "   > Deal 40 damage to target & activate scorpions if exists" << endl;
            cout << "Ability 2: SCORPION - energy = 4" << endl;
            cout << "   > Lock a scorpion on target, deals 20 damage each turn" << endl;
            cout << "   > If dagger calls them, each scorpion deals 60 damage" << endl;
            cout << "Special Ability: SCORPION'S TAIL - energy = 5" << endl;
            cout << "   > Quote: \"Did you see my sting? No? Well... you never will...\"" << endl;
            cout << "   > Pooya hides (only takes area damage) for 3 turns" << endl;
            cout << "   > After 3 turns, deals 450 damage to random enemy & returns" << endl;
            cout << "   > Cooldown: Once every 4 rounds" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
        else if (team[i] == 7)  
        {
            cout << "\n========================================" << endl;
            cout << "Agha Shahriar - Role: Joker" << endl;
            cout << "========================================" << endl;
            cout << "Ability 1: MOCK - energy = 2" << endl;
            cout << "   > Deal 60 damage to target" << endl;
            cout << "   > 20% chance of miss" << endl;
            cout << "Ability 2: STUBBORN - energy = 4" << endl;
            cout << "   > Deal 100 damage to random enemy (not the target)" << endl;
            cout << "Special Ability: WORLD INVERSION - energy = 8" << endl;
            cout << "   > Quote: \"Good becomes bad... bad becomes good... who am I? Agha Shahriar...\"" << endl;
            cout << "   > For 2 turns, everything reverses:" << endl;
            cout << "   > Damage to enemy becomes healing" << endl;
            cout << "   > Healing to teammate becomes damage" << endl;
            cout << "   > Cooldown: Once every 4 rounds" << endl;
            cout << "   > WARNING: This can destroy your own team!" << endl;
            cout << "_=======================================================================================================_"<<endl;

        }
 
    }
}


void controller::starting_team(string & A, string & B) //تعین تیم شروع کننده
{
    srand(time(nullptr));
    int random = rand() % 2;
    if(random == 0)
    {
        cout << "\n<< " << A << " Team goes first! >>\n\n";
    }
    else 
    {
        string help = A;
        A = B;
        B = help;
        cout << "\n<< " << A << " Team goes first! >>\n\n";
    }
}


int controller::Energy_level(const int round ,const bool t)  //تعین میزان انرژی
{
    if(t) 
    {
        switch (round)
        {
            case 1:
                return 5;

            case 2:
                return 8;

            case 3:
                return 9;

            default: 
                return 10;
        }
        
    } 
    else 
    {
        switch (round)
        {
            case 1:
                return 8;

            case 2:
                return 9;

            default: 
                return 10;
        }

    }
}

void controller::useEnergy(int& Energy , int amount) //استفاده از انزژی
{
    if(Energy >= amount) 
    {
        Energy -= amount;
    } else {
        cout << "you cann't use this ability." << endl;
    }
}


bool controller::end_game(Hero* ptrteam[]) const  //پایان بازی
{
    if(ptrteam[0]->checkalive() || ptrteam[1]->checkalive() || ptrteam[2]->checkalive())
    {
        return false;
    } 
    else 
    {
        return true; //end game 
    }
}


int controller::get_number() const
{
    return number;
}

controller::~controller()
{
}

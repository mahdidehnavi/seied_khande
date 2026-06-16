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
    cout << "│ 2  │ Taha Kuchike        │ Healer   │ 500  │\n";
    cout << "│ 3  │ Dani Golang         │ Defender │ 600  │\n";
    cout << "│ 4  │ Amin Emeni          │ Attacker │ 500  │\n";
    cout << "│ 5  │ Taha Bozorge        │ Attacker │ 500  │\n";
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
                    cout << "Taha Kuchike added to " << teamName << ".\n";
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
                    cout << "Amin Emeni added to " << teamName << ".\n";
                    k++;
                    break;
                    
                case 5:
                    team.push_back(5);
                    ptrteam[k] = new taha_b();
                    cout << "Taha Bozorge added to " << teamName << ".\n";
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
            cout << "Taha Kuchike" << endl;
        }        
        else if (team[i]== 3)
        {
            cout << "Dani Golang" << endl;
        }        
        else if (team[i]== 4)
        {
            cout << "Amin Emeni" << endl;
        }        
        else if (team[i]== 5)
        {
            cout << "Taha Bozorge" << endl;
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
            cout << "\t\t\t" << i+1 << ".Taha Kuchike  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 3)
        {
            cout << "\t\t\t" << i+1 << ".Dani Golang  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 4)
        {
            cout << "\t\t\t" << i+1 << ".Amin Emeni  HP : " << ptrteam[i]->get_hp() << endl;
        }        
        else if (team[i]== 5)
        {
            cout << "\t\t\t" << i+1 << ".Taha Bozorge  HP : " << ptrteam[i]->get_hp() << endl;
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

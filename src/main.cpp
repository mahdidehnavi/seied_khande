#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#include "controller.hpp"
#include "Hero.hpp"

int main()
{
    cout << "════════════════════════════════════════════════════════════════════ \n";
    cout << " welcome to the game : (SEYED KHANDEH) .                             \n";
    cout << "════════════════════════════════════════════════════════════════════  \n";
    
    srand(static_cast<unsigned int>(time(0))) ;

    string teamA_name;
    string teamB_name;

    cout << "Enter Team A Name : " ;
    getline(cin ,teamA_name);
    cout << "Enter Team B Name : " ;
    getline(cin ,teamB_name);
    
    controller k;
    k.starting_team(teamA_name,teamB_name);

    string command ;

        cout << "enter a number 1 or 2"<< endl;
        cout << "1  = (start game) "<< endl;
        cout << "2  = (end game) "<< endl;
        cout << "enter a number -> ";
        getline(cin,command);
        cout << "════════════════════════════════════════════════════════════════════ \n";

        
        if (command == "1")
        {
            Hero* ptrTeamA[3];//برای اطلعات بازیکنان  که به بازیکن اشاره می کردند 
            Hero* ptrTeamB[3];
            
            k.show_hero();
            cout << teamA_name << endl;
            k.teamA.clear();
            k.choice_heros(k.teamA, teamA_name , ptrTeamA);    
                         
            k.show_hero();
            cout << teamB_name << endl;
            k.teamB.clear();
            k.choice_heros(k.teamB, teamB_name , ptrTeamB);
            
            
            int round = 1;
            string team_name;
            string Enemy_name;
            Hero* ptTeam[3];
            Hero* ptEnemy[3];
            int namber;
            vector <int> team;
            vector <int> Enemy;

            while (round <= 15)
            {
                
                for(int j = 1 ; j >= 0 ; j--)
                {
                    if(j == 1) // team A
                    {
                        team_name = teamA_name;
                        Enemy_name = teamB_name;
                        for(int i = 0 ; i < 3 ; i++)
                        {
                            ptTeam[i] = ptrTeamA[i];    
                            ptEnemy[i] = ptrTeamB[i];    
                            team.push_back(k.teamA[i]); 
                            Enemy.push_back(k.teamB[i]);                       
                        }

                        for(int i = 0 ; i < 3 ; i++)
                        {
                           ptTeam[i]->check_rand(ptTeam ,  ptEnemy);
                        }
                    }
                    else  // team B
                    {
                        team_name = teamB_name;
                        Enemy_name = teamA_name;
                        for(int i = 0 ; i < 3 ; i++)
                        {
                            ptTeam[i] = ptrTeamB[i];
                            ptEnemy[i] = ptrTeamA[i];    
                            team.push_back(k.teamB[i]);          
                            Enemy.push_back(k.teamA[i]);                       
                        }
                        
                        
                        for(int i = 0 ; i < 3 ; i++)
                        {
                           ptTeam[i]->check_rand(ptTeam ,  ptEnemy);
                        }
                    }   
                    int energy = k.Energy_level(round , j);
                    
                    bool use = false;
                    int wHero;
                    int wAbility;


                    while(energy > 0)
                    {                     
                        cout << "═══════════════════════════════════════════════════════════════════════════ \n";
                        cout << "              " << team_name << " TURN    { Energy : " << energy << " }" << endl;
                        for(int i = 0 ; i < 3 ; i++){
                            cout << i+1 << ".";
                            ptTeam[i]->choice_ability();
                            cout << endl;
                        }

                        cout << "\t\t\tEnemy: " << Enemy_name << endl;
                        k.Enemy_Ability(Enemy , ptEnemy); 

                        cout << "0) End Turn" << endl;

                        cout << "Enter Hero number(1-3)(0 to End): ";
                        cin >> wHero;

                        if(wHero == 0){
                            cout << "⏭️ Turn Ended.\n";
                            break;
                        }

                        while(wHero < 0 || wHero > 3 || !ptTeam[wHero - 1]->checkalive())
                        {
                            if(wHero < 0 || wHero > 3)
                            {
                                cout << "Enter a correct Hero number(1-3)(0 to End): ";
                                cin >> wHero;
                                if(wHero == 0){
                                    break;
                                }
                            }
                            if(!ptTeam[wHero - 1]->checkalive() && wHero != 0)
                            {
                                cout << "☠️ This hero has been defeated!\nChoose another hero(0 to End): ";
                                cin >> wHero;
                                if(wHero == 0){
                                    break;
                                }
                            }
                        }

                        if(wHero == 0){
                            cout << "⏭️ Turn Ended.\n";
                            break;
                        }

                        cout << "Enter Ability number(1-3)(0 to End): ";
                        cin >> wAbility;

                        if(wAbility == 0){
                            cout << "⏭️ Turn Ended.\n";
                            break;
                        }
                        int helpi = 0;
                        while(wAbility < 0 || wAbility > 3 || !ptTeam[wHero -1]->checkRage() || energy < (ptTeam[wHero -1]->get_enerAbility(wAbility)))
                        {
                            if(wAbility < 0 || wAbility > 3)
                            {
                                cout << "Enter a correct Ability number(1-3)(0 to End): ";
                                cin >> wAbility;
                                if(wAbility == 0){
                                    break;
                                }
                                helpi = 1;
                            }
                            if(energy < (ptTeam[wHero -1]->get_enerAbility(wAbility)))
                            {
                                cout << "⚠️ Not enough energy to use this ability!\nChoose another Ability(0 to End): ";
                                cin >> wAbility;
                                if(wAbility == 0){
                                    break;
                                }
                                helpi = 1;
                            }
                            if(!ptTeam[wHero -1]->checkRage() && helpi == 0)
                            { 
                                if(wAbility != 3){
                                    break;
                                }
                                
                                cout << "🔒 Rage ability is locked!\nChoose another Ability(0 to End): ";

                                cin >> wAbility;
                            }
                            helpi = 0;
                        }

                        if(wAbility == 0){
                            cout << "⏭️ Turn Ended.\n";
                            break;
                        }
                        
                        if(wAbility == 3){
                            use = true;
                        }

                        energy -= ptTeam[wHero -1]->get_enerAbility(wAbility);


                        ptTeam[wHero - 1]->Ability(wAbility , ptTeam ,  ptEnemy );



                        if( k.end_game(ptTeam) && k.end_game(ptEnemy) )
                        {
                            cout << "\n\n🤝The game ended in a draw!";
                            cout << "\n🏁 Game Over!";
                            return 0;
                        }
                        else if ( k.end_game(ptTeam) )
                        {
                            cout << "\n\n🏆 Team " << team_name << " wins the game!";
                            cout << "\n🏁 Game Over!";
                            return 0;
                        }
                        else if ( k.end_game(ptEnemy) )
                        {
                            cout << "\n\n🏆 Team " << Enemy_name << " wins the game!";
                            cout << "\n🏁 Game Over!";
                            return 0;
                        }


                    }

                    for(int i = 0 ; i < 3 ; i++){
                        ptTeam[i]->apdateRageState(use);
                    }
                    team.clear();
                    Enemy.clear();

                }
                
                round++;
            }
        }
        else if (command == "2")
        {
            cout << "game is end (:" << endl;
            return 0;
        }
    
    

    return 0;
}

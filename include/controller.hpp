#pragma once
#include <string>
#include <vector>
#include "Hero.hpp"

class controller
{
private:

    int number;
    int enegry;
public:
    std::vector <int> teamA ;
    std::vector <int> teamB ;
    controller(/* args */);
    void starting_team(std::string & , std::string &);
    int Energy_level(const int , const bool);
    void useEnergy(int& Energy ,const int amount);
    void show_hero() const;   
    void choice_heros(std::vector<int>& team ,const std::string& teamName,Hero* ptrteam[]);
    void Enemy_Ability(std::vector<int>& team , Hero* ptrteam[]);
    void start_action(std::vector<int>& team, const std::string& teamName);
    bool end_game(Hero* ptrteam[]) const;
    int get_number() const;
    ~controller();
};


#pragma once
#include <string>
#include "Hero.hpp"

class dany_go : public Hero
{
private:
    int min_player;
public:
    dany_go();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    ~dany_go();
};
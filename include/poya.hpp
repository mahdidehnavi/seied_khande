#pragma once
#include <string>
#include "Hero.hpp"

class poya : public Hero
{
private:
    int rnd;
    int target;
public:
    poya();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void check1(Hero* ptTeam[] , Hero* ptEnemy[])override;
    void takedamage(int dmg) override;
    ~poya();
};
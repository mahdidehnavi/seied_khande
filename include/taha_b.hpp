#pragma once
#include <string>
#include "Hero.hpp"

class taha_b : public Hero
{
private:
    int round;   
public:
    taha_b();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void check1(Hero* ptTeam[] , Hero* ptEnemy[])override;
    void takedamage(const int dmg) override;
    ~taha_b();
};
#pragma once
#include <string>
#include "Hero.hpp"

class shahriar : public Hero
{
private:
    int rnd;
public:
    shahriar();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    ~shahriar();
};
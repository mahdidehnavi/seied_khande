#pragma once
#include <string>
#include "Hero.hpp"

class taha_k : public Hero
{
private:
    int round ;
public:
    taha_k();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    ~taha_k();
};


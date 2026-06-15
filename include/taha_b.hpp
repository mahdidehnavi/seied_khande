#pragma once
#include <string>
#include "Hero.hpp"

class taha_b : public Hero
{
private:
    
public:
    taha_b();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    ~taha_b();
};
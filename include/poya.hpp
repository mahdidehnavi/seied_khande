#pragma once
#include <string>
#include "Hero.hpp"

class poya : public Hero
{
private:
    
public:
    poya();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    ~poya();
};
#pragma once
#include <string>
#include "Hero.hpp"

class Dr_white : public Hero
{
private:
    
public:
    Dr_white();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    ~Dr_white();
};
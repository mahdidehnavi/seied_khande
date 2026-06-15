#pragma once
#include <string>
#include "Hero.hpp"

class dany_go : public Hero
{
private:
    
public:
    dany_go();
    void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) override; 
    void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) override;
    void choice_ability() override;
    ~dany_go();
};
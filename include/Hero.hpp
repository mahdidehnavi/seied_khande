#pragma once
#include <string>
class controller;

class Hero
{
protected:
    std::string name ;
    std::string role;
    int Hp;
    int MaxHp;
    std::string Angry_massage;
    int rageThreshold;
    int to_get_rage;
    int enrAbility1;
    int enrAbility2;
    int enrSpecAbility;
public:
    Hero(std::string n, std::string ro , int h , int rage , std::string AngMas, int enerA1 , int enerA2 , int enerspac);
    void Ability(int wAbility , Hero* ptTeam[] ,Hero* ptEnemy[]); 
    virtual void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) = 0; 
    virtual void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void choice_ability() = 0;
    void takedamage(const int dmg);
    void heal(const int);
    bool checkalive() const;
    bool checkRage()const;
    void apdateRageState(bool);
    std::string get_name() const;
    std::string get_role() const;
    int get_hp() const;
    int get_to_get_rage() const;
    std::string get_Angry_massage() const;
    int get_enrAbility1() const;
    int get_enrAbility2() const;
    int get_enrSpecAbility() const;
    int get_enerAbility(int) const;
    ~Hero();
};


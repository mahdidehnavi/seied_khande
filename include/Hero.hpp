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
    bool check = false;
    bool check2 = false;
    bool joker = false;
    int rnd = 0;
    int rnd_end = 10;
    bool doping = false;
    int ghofly = 0;
    int shield = 0 ;
    
public:
    Hero(std::string n, std::string ro , int h , int rage , std::string AngMas, int enerA1 , int enerA2 , int enerspac);
    void Ability(int wAbility , Hero* ptTeam[] ,Hero* ptEnemy[]); 
    virtual void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) = 0; 
    virtual void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void choice_ability() = 0;
    virtual void takedamage(int dmg);
    void heal(int amount);
    bool checkalive() const;
    bool checkRage()const;
    void apdateRageState();
    void check_rand(Hero* ptTeam[] , Hero* ptEnemy[]);
    virtual void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]);
    virtual void check1(Hero* ptTeam[] , Hero* ptEnemy[]);

    void set_hp(int);
    void set_doping(bool dop);
    void set_ghofly(int dmg);
    void set_shield(int shi);

    std::string get_name() const;
    std::string get_role() const;
    int get_hp() const;
    int get_to_get_rage() const;
    std::string get_Angry_massage() const;
    int get_enrAbility1() const;
    int get_enrAbility2() const;
    int get_enrSpecAbility() const;
    int get_enerAbility(int) const;
    bool get_check() const;
    bool get_check2() const;
    bool get_joker() const;
    bool get_doping() const; 
    int get_ghofly() const;
    ~Hero();
};


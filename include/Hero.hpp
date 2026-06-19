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
    int rnd_end;
    bool doping ;
    bool ghofly ;
    int dopeRounds ;
    int ghoflyRounds ;
    int shield = 0 ;


public:
    Hero(std::string n, std::string ro , int h , int rage , std::string AngMas, int enerA1 , int enerA2 , int enerspac);
    void Ability(int wAbility , Hero* ptTeam[] ,Hero* ptEnemy[]); 
    virtual void ability1(Hero* ptTeam[] , Hero* ptEnemy[]) = 0; 
    virtual void ability2(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void special_ablity(Hero* ptTeam[] , Hero* ptEnemy[]) = 0;
    virtual void choice_ability() = 0;
    virtual void takedamage(const int dmg);
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
    bool get_check() const;
    bool get_check2() const;
    bool get_joker() const;
    void check_rand(Hero* ptTeam[] , Hero* ptEnemy[]);
    virtual void after_rnd(Hero* ptTeam[] , Hero* ptEnemy[]);

    void set_doping(int rounds);
    void update_doping();
    int get_damage_with_dope(int Damage) const;
    int get_dopeRounds() const ;
    bool get_doping() const; 
    void set_shielt(int shi);
    void update_ghofly();
    int get_damage_with_ghofly(int damage) const;
    int get_ghoflyRounds() const ;
    bool get_ghofly() const;
    void set_ghofly(int rounds);

    ~Hero();
};


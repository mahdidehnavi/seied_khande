#include <iostream>
#include <string>
#include "Hero.hpp"

using namespace std;

Hero::Hero(string n, string ro , int h ,int rage , string AngMas , int enerA1 , int enerA2 , int enerspac)
{
    name = n;
    role = ro;
    Hp = h;
    MaxHp = h;
    rageThreshold = rage; 
    to_get_rage = rage;
    Angry_massage = AngMas;
    enrAbility1 = enerA1;
    enrAbility2 = enerA2;
    enrSpecAbility = enerspac;


    check  = false ;
    doping = false ;
    ghofly = false ;

}

void Hero::Ability(int wAbility,  Hero* ptTeam[] , Hero* ptEnemy[])
{
    switch (wAbility)
    {
        case 1:
            ability1(ptTeam , ptEnemy);
            break;
        case 2:
            ability2(ptTeam , ptEnemy);
            break;
        case 3:
            special_ablity(ptTeam , ptEnemy);
            break;
    }
}


void Hero::takedamage(const int dmg) // کم کردن جون از قهرمان
{
    Hp -= dmg;
    if(Hp < 0) Hp = 0;
}

void Hero::heal(const int amount) // اضافه کردن جون به قهرمان
{
    Hp += amount;
    if(Hp > MaxHp) Hp = MaxHp;
}

bool Hero::checkalive() const // چک کردن اینکه قهرمان زنده است یا نه
{
    if(Hp == 0)
    {
        return false;
    } 
    else {
        return true;
    }
}

bool Hero::checkRage() const //برای چک کردن اینکه میشه از خشم استفاده کرد یانه
{
    if(to_get_rage == 0){
        return true;
    } else {
        return false;
    }
}

void Hero::apdateRageState(bool use) //برای آپدیت وضعیت خشم
{
    if(use && to_get_rage == 0){
        to_get_rage = rageThreshold;
    } else {
        if(to_get_rage != 0){
            to_get_rage--;
        }
    }

}

string Hero::get_name() const
{
    return name;
}

string Hero::get_role() const
{
    return role;
}
    
int Hero::get_hp() const
{
    return Hp;
}

int Hero::get_to_get_rage() const
{
    return to_get_rage;
}

string Hero::get_Angry_massage() const
{
    return Angry_massage;
}

int Hero::get_enrAbility1() const
{
    return enrAbility1;
}

int Hero::get_enrAbility2() const
{
    return enrAbility2;
}

int Hero::get_enrSpecAbility() const
{
    return enrSpecAbility;
}

int Hero::get_enerAbility(int wAbility) const
{
    switch (wAbility)
    {
        case 1:
            return get_enrAbility1();
            break;
        case 2:
            return get_enrAbility2();
            break;
        case 3:
            return get_enrSpecAbility();
            break;
        default:
            return 0;
            break;
    }
}


bool Hero::get_check() const
{
    return check ;
}

void Hero::set_doping(int rounds)
{
    doping = true;
    dopeRounds = rounds ;
}

int  Hero::get_dopeRounds() const 
{
    return dopeRounds;
}

void Hero::update_doping()
{
    if (doping)
    {
        dopeRounds--;
        if (dopeRounds <= 0)
        {
            doping = false;
        }
    }
}

int  Hero::get_damage_with_dope(int Damage) const
{
    if (doping)
    {
        return Damage + (Damage * 20 / 100);
    }
    return Damage;
}



bool Hero::get_doping() const
{
    return doping;
}

void Hero::set_shielt(int shi)
{
    shield = shi ;
}



void Hero::update_ghofly()
{
    if (ghofly)
    {
        ghoflyRounds--;
        if (ghoflyRounds <= 0)
        {
            ghofly = false;
        }
    }
}
int Hero::get_damage_with_ghofly(int damage) const
{
    if (ghofly)
    {
        return damage + (damage * 16 / 100);
    }
    return damage;
}
int Hero::get_ghoflyRounds() const 
{
    return ghoflyRounds;
}
bool Hero::get_ghofly() const
{
    return ghofly;

}
void Hero::set_ghofly(int rounds)
{
    ghofly = true;
    ghoflyRounds = rounds ;  
}

Hero::~Hero()
{
}



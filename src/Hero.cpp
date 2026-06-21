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


void Hero::takedamage(int dmg) 
{
    if(doping)
    {
        dmg = dmg * 1.2;  
    }

    if(!joker)
    {
        int dmg2 = dmg;
        if(shield != 0)
        {
            int helpi = shield;
            shield -= dmg;
            dmg -= helpi;
            if(dmg < 0) dmg = 0;

            dmg2 -= dmg;

            cout << "the shield took " << dmg2 << " damage." << endl;
        }
        
        if(dmg != 0)
        {
            Hp -= dmg;
            if(Hp < 0) Hp = 0;
            cout << endl << name << " took " << dmg << " damage." << endl;
            cout << "   ❤️ Remaining HP: " << Hp << " / " << MaxHp << endl;
        }
    } 
    else 
    {
        Hp += dmg;
        if(Hp > MaxHp) Hp = MaxHp;
        cout << endl << " World reversal is active." << endl;
        cout << dmg << " HP restored to " << name << endl;
        cout << "   ❤️ Remaining HP: " << Hp << " / " << MaxHp << endl;
    }
}



void Hero::heal(int amount) 
{    if(!joker)
    {
        Hp += amount;
        if(Hp > MaxHp) Hp = MaxHp;
        cout << endl << amount << " HP restored to " << name << endl;
        cout << "   ❤️ Current HP: " << Hp << " / " << MaxHp << endl;
    } 
    else 
    {
        int dmg2 = amount;
        if(shield != 0)
        {
            int helpi = shield;
            shield -= amount;
            amount -= helpi;
            if(amount < 0) amount = 0;

            dmg2 -= amount;

            cout << "the shield took " << dmg2 << " damage." << endl;
        }
        
        if(amount != 0)
        {
            Hp -= amount;
            if(Hp < 0) Hp = 0;
            cout << endl << " World reversal is active." << endl;
            cout << name << " took " << amount << " damage." << endl;
            cout << "   ❤️ Current HP: " << Hp << " / " << MaxHp << endl;
        }
    }
}

bool Hero::checkalive() const 
{
    if(Hp == 0)
    {
        return false;
    } 
    else {
        return true;
    }
}

bool Hero::checkRage() const
{
    if(to_get_rage == 0){
        return true;
    } else {
        return false;
    }
}

void Hero::apdateRageState()
{
    if(to_get_rage != 0){
        to_get_rage--;
    }
    
}

void Hero::check_rand(Hero* ptTeam[] , Hero* ptEnemy[])
{
    if(check2 || joker)
    {
        rnd++;
    }
    
    if( rnd == rnd_end  )
    {
        rnd = 0;
        joker = false;
        check2 = false;
        after_rnd(ptTeam , ptEnemy);
    }
}

void Hero::after_rnd(Hero* ptTeam[] , Hero* ptEnemy[])
{
}

void Hero::check1(Hero* ptTeam[] , Hero* ptEnemy[])
{   
}



void Hero::set_hp(int h)
{
    Hp = h;
}

void Hero::set_doping(bool dop)
{
    doping = dop;
}

void Hero::set_ghofly(int dmg)
{
    ghofly = dmg;  
}

void Hero::set_shield(int shi)
{
    shield = shi;
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

bool Hero::get_check2() const
{
    return check2;
}

bool Hero::get_joker() const
{
    return joker;
}

bool Hero::get_doping() const
{
    return doping;
}

int Hero::get_ghofly() const
{
    return ghofly;

}


Hero::~Hero()
{
}



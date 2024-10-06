#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string humanB_name;
        Weapon *weapon;
    public:
        HumanB(std::string humanB_name);
        ~HumanB();
        void attack();
        void setWeapon(const Weapon& weapon);
};
#endif
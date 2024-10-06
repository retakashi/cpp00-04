#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string humanA_name;
        Weapon& weapon;
    public:
        HumanA(std::string humanA_name, Weapon& weapon);
        ~HumanA();
        void attack();
        void setWeapon(const Weapon& weapon);
};
#endif
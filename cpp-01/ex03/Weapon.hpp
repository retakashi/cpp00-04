#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
    private:
        std::string weapon_type;
    public:
        Weapon(std::string weapon_type);
        ~Weapon();
        const std::string&    getType();
        void    setType(const std::string& weapon_type);
};
#endif
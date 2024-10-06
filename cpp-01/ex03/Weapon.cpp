#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
    this->weapon_type = weapon_type;
}

Weapon::~Weapon()
{
}

const std::string&    Weapon::getType()
{
    return (this->weapon_type);
}

void    Weapon::setType(const std::string& weapon_type)
{
    this->weapon_type = weapon_type;
}
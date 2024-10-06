#include "HumanB.hpp"

HumanB::HumanB( std::string humanB_name ) : humanB_name(humanB_name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (this->weapon == NULL || this->weapon->getType().empty())
        std::cout << this->humanB_name << " attacks without any weapon." << std::endl;
    else
        std::cout << this->humanB_name << " attacks with their " << this->weapon->getType() << "." << std::endl;
}

void HumanB::setWeapon(const Weapon& weapon )
{
    this->weapon = &weapon;
}
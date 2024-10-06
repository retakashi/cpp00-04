#include "HumanA.hpp"

HumanA::HumanA( std::string humanA_name, Weapon& weapon ) : humanA_name(humanA_name), weapon(weapon) {
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << this->humanA_name << " attacks with their " << this->weapon.getType() << "." << std::endl;
}

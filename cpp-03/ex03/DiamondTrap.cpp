#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name+"_clap_name"),ScavTrap(name), FragTrap(name),className(name)
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other.name +"_clap_name" ),ScavTrap(other.name),FragTrap(other.name),className(other.name)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if(this != &other)
        *this = other;
    return(*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "name is " << this->getClassName() << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::getName() << std::endl;
}

const std::string& DiamondTrap::getClassName()
{
    return (this->className);
}

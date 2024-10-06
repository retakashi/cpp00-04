#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap Default constructor called" << std::endl;
  this->hitPoints = 100;
  this->energyPoints = 50;
  this->attackDamage = 20;
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name) {
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  if (this != &other) *this = other;
  return (*this);
}

void ScavTrap::attack(const std::string& target) {
  if (this->CanClaptrapDoAnything() == false) {
    std::cout << "ScavTrap " << this->getName() << " can't attack."
              << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
  this->energyPoints--;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
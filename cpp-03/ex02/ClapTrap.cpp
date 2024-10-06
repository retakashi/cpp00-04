#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& other) {
  std::cout << "ClapTrap Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap Copy assignment operator called" << std::endl;
  if (this != &other) *this = other;
  return (*this);
}

void ClapTrap::attack(const std::string& target) {
  if (this->CanClaptrapDoAnything() == false) {
    std::cout << "ClapTrap " << this->getName() << " can't attack."
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->getName() << " attacks " << target
            << ", causing " << this->getAttackDamage() << " points of damage!"
            << std::endl;
  this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->CanClaptrapDoAnything() == false) {
    std::cout << "ClapTrap " << this->getName() << " is already dead."
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->getName() << " took damage and lost "
            << amount << " points." << std::endl;
  if (this->getHitPoints() <= amount)
    this->hitPoints = 0;
  else
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->CanClaptrapDoAnything() == false) {
    std::cout << "ClapTrap " << this->getName() << " can't repaire."
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->getName() << " repaired " << amount
            << " points." << std::endl;
  this->energyPoints--;
  if (UINT_MAX - this->hitPoints <= amount)
    this->hitPoints = UINT_MAX;
  else
    this->hitPoints += amount;
}

const std::string& ClapTrap::getName() const { return (this->name); }

const unsigned int& ClapTrap::getHitPoints() const { return (this->hitPoints); }

const unsigned int& ClapTrap::getEnergyPoints() const {
  return (this->energyPoints);
}

const unsigned int& ClapTrap::getAttackDamage() const {
  return (this->attackDamage);
}

bool ClapTrap::CanClaptrapDoAnything() const {
  if (this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0) return (false);
  return (true);
}

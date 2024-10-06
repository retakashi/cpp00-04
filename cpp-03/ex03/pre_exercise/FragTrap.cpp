#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap Default constructor called" << std::endl;
  this->hitPoints = 100;
  this->energyPoints = 100;
  this->attackDamage = 30;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name) {
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
  if (this != &other) *this = other;
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap Give me five!!" << std::endl;
}

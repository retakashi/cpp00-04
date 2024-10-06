#include "DiamondTrap.hpp"

__attribute__((destructor)) static void destructor() {
  system("leaks -q diamondtrap");
}

int main() {
  DiamondTrap diamond("diamond");
  ClapTrap *base;
  base = &diamond;
  std::cout << "[ diamond result ]" << std::endl;
  std::cout << "diamond name: " << diamond.getClassName() << std::endl;
  std::cout << "ClapTrap name: " << diamond.getName() << std::endl;
  std::cout << "hitpoints: " << diamond.getHitPoints() << std::endl; //FragTrap
  std::cout << "energypoints: " << diamond.getEnergyPoints() << std::endl; //ScavTrap
  std::cout << "attackdamage: " << diamond.getAttackDamage() << std::endl; //FragTrap

  std::cout << "\n[ base result ]"<< std::endl;
  std::cout << "ClapTrap name: " << base->getName() << std::endl;
  std::cout << "hitpoints: " << base->getHitPoints() << std::endl; //FragTrap
  std::cout << "energypoints: " << base->getEnergyPoints() << std::endl; //ScavTrap
  std::cout << "attackdamage: " << base->getAttackDamage() << std::endl; //FragTrap
  base->attack("target");
  return (0);
}

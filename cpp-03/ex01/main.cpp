#include "ScavTrap.hpp"

__attribute__((destructor)) static void destructor() {
  system("leaks -q scavtrap");
}

int main() {
  ScavTrap *n_derived = new ScavTrap("n_derived");
  ScavTrap s_derived("s_derive");
  ClapTrap *base;
  ScavTrap p_derived("p_derived");
  base = &p_derived;

  std::cout << "[ p_derived result ]" << std::endl;
  std::cout << "p_derived" << base->getName() << std::endl;
  base->attack("target");  // ScavTrap's attack
  base->beRepaired(UINT_MAX);
  base->takeDamage(100);
  for (int i = 0; i < 50; i++) base->attack("target");
    base->beRepaired(10);
  std::cout << "\n[ s_derived result ]" << std::endl;
  std::cout << "s_derived name: " << s_derived.getName() << std::endl;
  s_derived.attack("target");
  s_derived.takeDamage(10);
  s_derived.beRepaired(10);
  s_derived.guardGate();

  std::cout << "\n[ n_derived result ]" << std::endl;
  std::cout << "n_derived name: " << s_derived.getName() << std::endl;
  n_derived->takeDamage(100);
  n_derived->guardGate();
  n_derived->beRepaired(100);
  n_derived->guardGate();
  n_derived->attack("target");
  delete n_derived;
  return (0);
}

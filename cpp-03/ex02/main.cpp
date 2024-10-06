#include "FragTrap.hpp"

__attribute__((destructor)) static void destructor() {
  system("leaks -q fragtrap");
}

int main() {
  FragTrap s_fragtrap("s_fragtrap");
  FragTrap *n_fragtrap = new FragTrap("n_fragtrap");
  std::cout << "[ s_fragtrap result ]" << std::endl;
  std::cout << "s_fragtrap name: " << s_fragtrap.getName() << std::endl;
  s_fragtrap.attack("target");
  s_fragtrap.beRepaired(0);
  s_fragtrap.takeDamage(100);
  s_fragtrap.highFivesGuys();
  std::cout << "[ n_fragtrap result ]" << std::endl;
  n_fragtrap->beRepaired(UINT_MAX);
  n_fragtrap->attack("");
  n_fragtrap->takeDamage(UINT_MAX);
  n_fragtrap->attack("");
  delete n_fragtrap;
  return (0);
}

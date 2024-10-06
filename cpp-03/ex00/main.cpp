#include "ClapTrap.hpp"

int main() {
  ClapTrap c1("c1");
  ClapTrap c2("c2");

  std::cout << "[ c1 result ]" << std::endl;
  std::cout << "c1 name: " << c1.getName() << std::endl;
  c1.attack("target1");
  c1.takeDamage(UINT_MAX);
  c1.takeDamage(UINT_MAX);
  c1.beRepaired(UINT_MAX - 9);

  std::cout << "\n[ c2 result ]" << std::endl;
  std::cout << "c2 name: " << c2.getName() << std::endl;
  c2.attack("target2");
  c2.takeDamage(0);
  c2.beRepaired(UINT_MAX - 9);
  for (unsigned int i = 0; i < 10; i++) c2.beRepaired(100);
  c2.attack("target2");
  return (0);
}

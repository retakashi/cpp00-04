#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./pre_exercise/FragTrap.hpp"
#include "./pre_exercise/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  std::string className;
 public:
  DiamondTrap(std::string name);
  ~DiamondTrap();
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  void whoAmI();
  const std::string& getClassName();
};
#endif
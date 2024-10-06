#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  virtual void attack(const std::string& target);
  void guardGate();
};

#endif
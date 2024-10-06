#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {
 protected:
  std::string name;
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;
  bool CanClaptrapDoAnything() const;

 public:
  ClapTrap(std::string name);
  virtual ~ClapTrap();
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  const std::string& getName() const;
  const unsigned int& getHitPoints() const;
  const unsigned int& getEnergyPoints() const;
  const unsigned int& getAttackDamage() const;
};
#endif
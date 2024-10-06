#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 protected:
 static const int total = 4;
  std::string name;
  AMateria *inventory[total];
 public:
  Character(std::string name);
  Character(const Character& other);
  ~Character();
  Character& operator=(const Character& other);
  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};
#endif

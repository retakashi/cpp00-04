#ifndef WRONG_HPP
#define WRONG_HPP

#include "Animal.hpp"

class WrongAnimal
{
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);
  ~WrongAnimal();
  void makeSound() const;
  const std::string &getType() const;
};
std::ostream &operator<<(std::ostream &os, const WrongAnimal &that);
#endif

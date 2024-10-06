#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
  Brain *brainP;

public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog();
  virtual void makeSound() const;
  Brain *getBrainPointer() const;
};
std::ostream &operator<<(std::ostream &os, const Dog &that);
#endif

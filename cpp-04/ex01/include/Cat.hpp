#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain *brainP;

 public:
  Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat();
  virtual void makeSound() const;
  Brain *getBrainPointer() const;
};
std::ostream &operator<<(std::ostream &os, const Cat &that);
#endif

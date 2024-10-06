#include "Dog.hpp"

Dog::Dog() : brainP(new Brain)
{
  std::cout << "Dog Default constructor called" << std::endl;
  this->type = "dog";
}

Dog::Dog(const Dog &other)
{
  std::cout << "Dog Copy constructor called" << std::endl;
  *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
  std::cout << "Dog Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.getType();
  return (*this);
}

Dog::~Dog()
{
  std::cout << "Dog Destructor called" << std::endl;
  delete brainP;
}

void Dog::makeSound() const { std::cout << "bowwow🐶!!!!!!!!" << std::endl; }

Brain *Dog::getBrainPointer() const { return (this->brainP); }

std::ostream &operator<<(std::ostream &os, const Dog &that) {
  os << "type: " << that.getType() << std::endl;
  std::cout << "makeSound: ";
  that.makeSound();
  os << "brainP: " << that.getBrainPointer() << std::endl;
  return (os);
}

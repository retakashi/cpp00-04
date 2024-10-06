#include "Dog.hpp"

Dog::Dog()
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

Dog::~Dog() { std::cout << "Dog Destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "bowwow🐶!!!!!!!!" << std::endl; }
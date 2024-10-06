#include "Cat.hpp"

Cat::Cat()
{
  std::cout << "Cat Default constructor called" << std::endl;
  this->type = "cat";
}

Cat::Cat(const Cat &other)
{
  std::cout << "Cat Copy constructor called" << std::endl;
  *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
  std::cout << "Cat Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.getType();
  return (*this);
}

Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "meow😺!!!!!!!!!!!!" << std::endl; }

#include "Animal.hpp"

Animal::Animal() : type("notype")
{
  std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
  std::cout << "Animal Copy constructor called" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
  std::cout << "Animal Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.getType();
  return (*this);
}

Animal::~Animal()
{
  std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
  std::cout << "Not an animal of any kind" << std::endl;
}

const std::string &Animal::getType() const { return (this->type); }
std::ostream &operator<<(std::ostream &os, const Animal &that)
{
  os << "type: " << that.getType() << std::endl;
  os << "makeSound result: ";
  that.makeSound();
  return (os);
}

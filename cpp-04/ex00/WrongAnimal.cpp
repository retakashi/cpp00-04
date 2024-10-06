#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("notype")
{
  std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
  std::cout << "WrongAnimal Copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
  std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.getType();
  return (*this);
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal Destructor called" << std::endl;
}

const std::string &WrongAnimal::getType() const { return (this->type); }

void WrongAnimal::makeSound() const
{
  std::cout << "WrongAnimal Not an animal of any kind" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const WrongAnimal &that)
{
  os << "type: " << that.getType() << std::endl;
  os << "makeSound result: ";
  that.makeSound();
  return (os);
}

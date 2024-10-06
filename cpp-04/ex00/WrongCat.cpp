#include "WrongCat.hpp"

WrongCat::WrongCat()
{
  std::cout << "WrongCat Default constructor called" << std::endl;
  this->type = "cat";
}

WrongCat::WrongCat(const WrongCat &other)
{
  std::cout << "WrongCat Copy constructor called" << std::endl;
  *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
  std::cout << "WrongCat Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.getType();
  return (*this);
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
  std::cout << "meow😺!!!!!!!!!" << std::endl;
}

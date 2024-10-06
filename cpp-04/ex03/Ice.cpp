#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other.type) { *this = other; }

Ice::~Ice(){};

Ice &Ice::operator=(const Ice &other)
{
  if (this != &other)
    this->type = other.type;
  return (*this);
}

std::string const &Ice::getType() const { return (this->type); }

AMateria *Ice::clone() const
{
  AMateria *ret = new Ice();
  return (ret);
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) { *this = other; }

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) this->type = other.type;
  return (*this);
}

std::string const& AMateria::getType() const { return (this->type); }

void AMateria::use(ICharacter& target) {
  std::cout << target.getName() << ": Member function of AMateria" << std::endl;
}

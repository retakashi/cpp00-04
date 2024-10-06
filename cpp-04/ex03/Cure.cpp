#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other.type) { *this = other; }

Cure::~Cure(){};

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) this->type = other.type;
  return (*this);
}

std::string const& Cure::getType() const { return (this->type); }

AMateria* Cure::clone() const {
  AMateria* ret = new Cure();
  return (ret);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << " s wounds *" << std::endl;
}

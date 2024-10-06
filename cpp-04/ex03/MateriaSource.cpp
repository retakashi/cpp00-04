#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
  for (int i = 0; i < total; i++) this->inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < total; i++) {
    if (this->inventory[i] != NULL) delete this->inventory[i];
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  for (int i = 0; i < total; i++) {
    if (this->inventory[i] != NULL) delete this->inventory[i];
    this->inventory[i] = other.inventory[i]->clone();
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
  int i;
  i = 0;
  if (m == NULL) {
    std::cout << "argument is null" << std::endl;
    return;
  }
  while (i < total && this->inventory[i] != NULL) i++;
  if (i == total) {
    std::cout << "Inventory is full" << std::endl;
    return;
  }
  if (m != NULL)
  this->inventory[i] = m->clone();
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  int i;
  i = 0;
  while (i < total && this->inventory[i] != NULL &&
         this->inventory[i]->getType() != type)
    i++;
  if (i == total) return (0);
  return (this->inventory[i]->clone());
}

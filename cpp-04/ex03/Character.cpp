#include "Character.hpp"

Character::Character(std::string name) : ICharacter(),name(name){
  for (int i = 0; i < total; i++) this->inventory[i] = NULL;
}

Character::Character(const Character& other):ICharacter() { *this = other; }

Character::~Character() {
  for (int i = 0; i < total; i++) {
    if (this->inventory[i] != NULL) delete this->inventory[i];
  }
}

Character& Character::operator=(const Character& other) {
  if (this != &other) this->name = other.name;
  for (int i = 0; i < total; i++) {
    if (this->inventory[i] != NULL) delete this->inventory[i];
    this->inventory[i] = other.inventory[i]->clone();
  }
  return (*this);
}

std::string const& Character::getName() const { return (this->name); }

void Character::equip(AMateria* m) {
  int i;

  i = 0;
  if (m == NULL) {
    std::cout << "Argument is null" << std::endl;
    return;
  }
  while (i < total && this->inventory[i] != NULL) i++;
  if (i == total) {
    std::cout << "Inventory is full" << std::endl;
    return;
  }
  this->inventory[i] = m->clone();
}

void Character::unequip(int idx) {
  if (!(idx >= 0 && idx < total)) {
    std::cout << "Invalid index" << std::endl;
    return;
  }
  this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (!(idx >= 0 && idx < total)) {
    std::cout << "Invalid index" << std::endl;
    return;
  }
  if (this->inventory[idx] == NULL) {
    std::cout << "Inventory[" << idx << "]"
              << " is null" << std::endl;
    return;
  }
  this->inventory[idx]->use(target);
}

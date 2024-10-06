#include "Cat.hpp"

Cat::Cat() : brainP(new Brain) {
  std::cout << "Cat Default constructor called" << std::endl;
  this->type = "cat";
}

Cat::Cat(const Cat &other) : brainP(new Brain(*other.brainP)) {
  std::cout << "Cat Copy constructor called" << std::endl;
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called" << std::endl;
  if (this != &other) {
    if (this->brainP != NULL) delete this->brainP;
    this->brainP = new Brain(*other.brainP);
    this->type = other.getType();
  }
  return (*this);
}

Cat::~Cat() {
  std::cout << "Cat Destructor called" << std::endl;
  if (this->brainP != NULL) delete brainP;
}

void Cat::makeSound() const { std::cout << "meow😺!!!!!!!!!!!!" << std::endl; }

Brain *Cat::getBrainPointer() const { return (this->brainP); }

std::ostream &operator<<(std::ostream &os, const Cat &that) {
  os << "type: " << that.getType() << std::endl;
  std::cout << "makeSound: ";
  that.makeSound();
  os << "brainP: " << that.getBrainPointer() << std::endl;
  return (os);
}

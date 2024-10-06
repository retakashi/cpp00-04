#include "Fixed.hpp"

Fixed::Fixed() : internalFixed(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) : internalFixed(value * (1 << this->bits)) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) : internalFixed(roundf((value) * (float)(1 << this->bits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& a){
  std::cout << "Copy constructor called" << std::endl;
  *this = a;
}

Fixed& Fixed::operator=(const Fixed& c) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->internalFixed = c.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  return (this->internalFixed);
}

void Fixed::setRawBits(int const raw) { this->internalFixed = raw; }

float Fixed::toFloat(void) const {
  return ((float)(this->internalFixed)) / (float)(1 << this->bits);
}

int Fixed::toInt(void) const {
  return (this->toFloat());
}

std::ostream& operator<<(std::ostream& os, const Fixed& c) {
  os << c.toFloat();
  return (os);
}

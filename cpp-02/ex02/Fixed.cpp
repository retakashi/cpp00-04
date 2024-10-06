#include "Fixed.hpp"

Fixed::Fixed() : internalFixed(0)
{
}

Fixed::Fixed(int value) : internalFixed(value * (1 << this->bits))
{
}

Fixed::Fixed(float value)
    : internalFixed(roundf((value) * (float)(1 << this->bits)))
{
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &a)
{
  *this = a;
}

Fixed &Fixed::operator=(const Fixed &c)
{
  this->internalFixed = c.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->internalFixed); }

void Fixed::setRawBits(int const raw) { this->internalFixed = raw; }

float Fixed::toFloat(void) const
{
  return ((float)(this->internalFixed)) / (float)(1 << this->bits);
}

int Fixed::toInt(void) const { return (this->toFloat()); }

bool Fixed::operator>(const Fixed &c) const
{
  return (this->getRawBits() > c.getRawBits());
}

bool Fixed::operator<(const Fixed &c) const
{
  return (this->getRawBits() < c.getRawBits());
}

bool Fixed::operator>=(const Fixed &c) const
{
  return (this->getRawBits() >= c.getRawBits());
}

bool Fixed::operator<=(const Fixed &c) const
{
  return (this->getRawBits() <= c.getRawBits());
}

bool Fixed::operator==(const Fixed &c) const
{
  return (this->getRawBits() == c.getRawBits());
}

bool Fixed::operator!=(const Fixed &c) const
{
  return (this->getRawBits() != c.getRawBits());
}

Fixed Fixed::operator*(const Fixed &c)
{
  Fixed ret(this->toFloat() * c.toFloat());
  return (ret);
}

Fixed Fixed::operator+(const Fixed &c)
{
  Fixed ret(this->toFloat() + c.toFloat());
  return (ret);
}

Fixed Fixed::operator-(const Fixed &c)
{
  Fixed ret(this->toFloat() - c.toFloat());
  return (ret);
}

Fixed Fixed::operator/(const Fixed &c)
{
  Fixed ret(this->toFloat() / c.toFloat());
  return (ret);
}

Fixed &Fixed::operator++()
{
  this->internalFixed++;
  return (*this);
}

Fixed Fixed::operator++(int)
{
  Fixed ret = *this;
  ++*this;
  return (ret);
}

Fixed &Fixed::operator--()
{
  this->internalFixed--;
  return (*this);
}

Fixed Fixed::operator--(int)
{
  Fixed ret = *this;
  --*this;
  return (Fixed(ret));
}

Fixed &Fixed::min(Fixed &c1, Fixed &c2)
{
  if (c1 > c2)
    return (c2);
  return (c1);
}

const Fixed &Fixed::min(const Fixed &c1, const Fixed &c2)
{
  if (c1 > c2)
    return (c2);
  return (c1);
}

Fixed &Fixed::max(Fixed &c1, Fixed &c2)
{
  if (c1 > c2)
    return (c1);
  return (c2);
}

const Fixed &Fixed::max(const Fixed &c1, const Fixed &c2)
{
  if (c1 > c2)
    return (c1);
  return (c2);
}

// global
std::ostream &operator<<(std::ostream &os, const Fixed &c)
{
  os << c.toFloat();
  return (os);
}

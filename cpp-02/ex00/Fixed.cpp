#include "Fixed.hpp"

Fixed::Fixed():fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNumber = a.getRawBits();
}

Fixed& Fixed::operator = (const Fixed& c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(c.getRawBits());
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointNumber = raw;
}


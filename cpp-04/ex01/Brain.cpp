#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain Default constructor called" << std::endl; }

Brain::Brain(const Brain &other)
{
  std::cout << "Brain Copy constructor called" << std::endl;
  *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
  std::cout << "Brain Copy assignment operator called" << std::endl;
  for (int i = 0; i < strArrLen; i++)
    this->ideas[i] = other.ideas[i];
  return (*this);
}

Brain::~Brain() { std::cout << "Brain Destructor called" << std::endl; }

const std::string Brain::getIdeas(int i) const
{
  if (i >= 0 && i < strArrLen)
    return (this->ideas[i]);
  std::cout << "getIdeas: Invalid index." << std::endl;
  return ("");
}

void Brain::setIdeas(int i, std::string str)
{
  if (!(i >= 0 && i < strArrLen))
  {
    std::cout << "setIdeas: Invalid index." << std::endl;
    return;
  }
  this->ideas[i] = str;
}

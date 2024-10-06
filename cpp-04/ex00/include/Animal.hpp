#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();
    virtual void makeSound() const;
    const std::string &getType() const;
};
std::ostream &operator<<(std::ostream &os, const Animal &that);
#endif

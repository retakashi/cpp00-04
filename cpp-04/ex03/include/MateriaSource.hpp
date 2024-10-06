#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 protected:
  static const int total = 4;
  AMateria* inventory[total];

 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  virtual void learnMateria(AMateria *m);
  virtual AMateria* createMateria(std::string const& type);
};
#endif

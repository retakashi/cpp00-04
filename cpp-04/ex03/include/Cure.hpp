#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& other);
  ~Cure();
  Cure& operator=(const Cure& other);
  std::string const& getType() const;  // Returns the materia type
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target); 
};

#endif

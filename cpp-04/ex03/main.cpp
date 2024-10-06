#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

// __attribute__((destructor)) static void destructor()
// {
//   system("leaks -q materia");
// }

int main()
{
  IMateriaSource *src = new MateriaSource();
  Ice *ice = new Ice();
  Cure *cure = new Cure();
  src->learnMateria(ice);
  delete ice;
  src->learnMateria(cure);
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  delete tmp;
  tmp = src->createMateria("cure");
  me->equip(tmp);
  delete tmp;
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
  // delete ice;
  delete cure;
  return 0;
}

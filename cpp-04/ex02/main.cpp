#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q brain");
// }

int main()
{
  {
    std::cout << "\n[ a result ]" << std::endl;
    Animal *a = new Cat;
    std::cout << std::endl;
    std::cout << *a;
    delete a;
  }
  {
    std::cout << "\n[ c1 result ]" << std::endl;
    Cat c1;
    std::cout << std::endl;
    std::cout << c1;
    c1.getBrainPointer()->setIdeas(0, "hello");
    c1.getBrainPointer()->setIdeas(100, "hello");
    std::cout << "Ideas: " << c1.getBrainPointer()->getIdeas(0) << std::endl;
    std::cout << "Ideas: " << c1.getBrainPointer()->getIdeas(100);
  }
  {
    std::cout << "\n[ d1 result ]" << std::endl;
    Dog d1;
    Dog d2(d1);
    std::cout << std::endl;
    std::cout << d1;
    d1.getBrainPointer()->setIdeas(-1, "hello");
    d1.getBrainPointer()->setIdeas(2, "hello2");
    std::cout << "Ideas: " << d1.getBrainPointer()->getIdeas(-1);
    std::cout << "Ideas: " << d1.getBrainPointer()->getIdeas(2) << std::endl;
    std::cout << std::endl;
  }
  // ⇩compile error
  // Animal a;
  // Animal *newA = new Animal;
  return 0;
}

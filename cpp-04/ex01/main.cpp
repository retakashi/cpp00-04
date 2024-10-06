#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

__attribute__((destructor)) static void destructor() {
  system("leaks -q brain");
}

int main() {
  {
    std::cout << "\n[ c1 result ]" << std::endl;
    Cat c1;
    std::cout << c1;
    c1.getBrainPointer()->setIdeas(0, "hello");
    c1.getBrainPointer()->setIdeas(-1, "hello");
    std::cout << "Ideas: " << c1.getBrainPointer()->getIdeas(0) << std::endl;
    std::cout << "\n[ c2 result ]" << std::endl;
    Cat c2(c1);
    std::cout << c2;
    c2.getBrainPointer()->setIdeas(2, "hello2");
    c1.getBrainPointer()->setIdeas(INT_MAX, "hello");
    std::cout << "Ideas: " << c2.getBrainPointer()->getIdeas(2) << std::endl;
    std::cout << "Ideas: " << c2.getBrainPointer()->getIdeas(-1) << std::endl;
  }
  {
    std::cout << "\n[ d1 result ]" << std::endl;
    Dog d1;
    std::cout << d1;
    d1.getBrainPointer()->setIdeas(0, "hello");
    std::cout << "Ideas: " << d1.getBrainPointer()->getIdeas(0) << std::endl;
    std::cout << "\n[ d2 result ]" << std::endl;
    Dog d2;
    d1 = d2;
    std::cout << d2;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  Animal *animalArr[10];
  for (int i = 0; i < 10; i++) {
    if (i < 10 / 2)
      animalArr[i] = new Cat;
    else
      animalArr[i] = new Dog;
  }
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "animalArr[ " << i << " ]: " << animalArr[i]->getType()
              << std::endl;
    animalArr[i]->makeSound();
  }
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) delete animalArr[i];
  return 0;
}

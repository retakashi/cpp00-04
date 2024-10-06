#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q animal");
// }

int main()
{
    {
        std::cout << "\n[ meta result ]" << std::endl;
        const Animal *meta = new Animal();
        std::cout << *meta;
        delete meta;
    }
    {
        std::cout << "\n[ j result ]" << std::endl; // dog
        const Animal *j = new Dog();
        std::cout << *j;
        delete j;
        std::cout << "\n[ i result ]" << std::endl; // cat
        const Animal *i = new Cat();
        std::cout << *i;
        delete i;
    }
    {
        std::cout << "\n[w_animal result ]" << std::endl; // wronganimal
        const WrongAnimal *w_animal = new WrongCat();
        std::cout << *w_animal;
        delete w_animal;
    }
    {
        std::cout << "\n[ c1 result ]" << std::endl;
        Cat c1;
        Cat c2(c1);
        std::cout << c1;
    }
    return 0;
}

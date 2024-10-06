#include "Zombie.hpp"

__attribute__((destructor))
static void destructor() {
    system("leaks -q zombie");
}

int main()
{
    Zombie *newhorde;
    int N;
    int i;
    std::string name = "aaa";

    N = 5;
    i = 0;
    newhorde = zombieHorde(N, name);
    std::cout << "[ Result of zombieHorde ]" << std::endl; 
    while (i < N)
    {
        newhorde[i].announce();
        i++;
    }
    std::cout << "\n[ destructor ]" << std::endl;
    delete[] newhorde;
    return (0);
}
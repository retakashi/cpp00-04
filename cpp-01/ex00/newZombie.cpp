#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *newzombie;
    try
    {
        newzombie = new Zombie(name);
        return (newzombie);
    }
    catch(const std::bad_alloc)
    {
        std::cout << "Failed to new." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}
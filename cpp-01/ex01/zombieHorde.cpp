#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *newhorde;
    int i;
    
    i = 0;
    try
    {
        newhorde = new Zombie[N];
        while (i < N)
        {
            newhorde[i].set_data(name, i);
            i++;
        }
        return (newhorde);
    }
    catch(const std::bad_alloc)
    {
        std::cerr <<"Failed to new." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}
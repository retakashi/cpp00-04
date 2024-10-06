#include "Zombie.hpp"

std::string getName(std::string name)
{
    std::string ret;
    
    ret = "";
    while (ret.empty())
    {
        std::cout << "Please enter a " << name << " > " << std::flush;
        if (!getline(std::cin, ret))
        {
            std::cout << "Failed to getline." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        else if (ret.empty())
            std::cout << "Nameless zombie...\n";
    }
    return (ret);
}

int main()
{
    std::string newname;
    std::string rCname;
    Zombie  *newzombie;

    newname = getName("newname");
    rCname = getName("rCname");
    newzombie = newZombie(newname);
    newzombie->announce();
    randomChump(rCname);
    delete newzombie;
    return (0);
}
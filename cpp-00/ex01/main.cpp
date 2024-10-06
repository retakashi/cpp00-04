#include "PhoneBook.hpp"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q phonebook");
// }

int main()
{
    PhoneBook   phonebook;
    std::string cmd;
    int add_i;

    cmd = "";
    add_i = 0;
    while (cmd != "EXIT")
    {
        std::cout << "Please enter a command : ADD / SEARCH / EXIT > " << std::flush;
        if (!getline(std::cin, cmd))
            phonebook.put_error("\nFailed to getline.");
        if (cmd == "ADD")
            phonebook.add_contact(&add_i);
        else if (cmd == "SEARCH")
            phonebook.search_contact(add_i);
        else if (cmd != "EXIT")
            std::cout << "Invalid command." << std::endl;
    }
    std::cout << "Exit👋" << std::endl;
    return (0);
}
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::get_field(std::string str)
{
    std::string new_field;

    new_field = "";
    std::cout << "Please enter " << str << " > " << std::flush;
    while (new_field.empty())
    {
        if (!getline(std::cin, new_field))
            put_error("\nFailed to getline");
        if (new_field.empty())
        {
            std::cout << str << " is empty." << std::endl;
            std::cout << "Please enter " << str << " > " << std::flush; 
        }
    }
    return (new_field);
}

void    PhoneBook::add_contact(int *add_i)
{
    t_new_fields new_fields;

    new_fields.new_first = get_field("the first name");
    new_fields.new_last = get_field("the last name");
    new_fields.new_nickname = get_field("the nickname");
    new_fields.new_number = get_field("the phone number");
    new_fields.new_secret = get_field("the darkest secret");
    this->contacts[*add_i % 8].set_fields(new_fields);
    *add_i+=1;
}

void    PhoneBook::search_contact(int total_i)
{
    int n;

    if (total_i == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }
    n = 0;
    this->output_phonebook(total_i);
    std::cout << "Please enter the index of the phonebook you want to display > " << std::flush;
    std::cin >> n;
    while (n < 0 || n >= total_i || n >= contact_max || !std::cin.good())
    {
        if (std::cin.eof())
            put_error("\nFailed to getline.");
        std::cout << "Invalid number." << std::endl;
        std::cout << "Please enter the index of the phonebook you want to display > " << std::flush;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    this->contacts[n].output_selected_contact();
}

void PhoneBook::output_phonebook(int total_i)
{
    int i;

    i = 0;
    if (total_i >= contact_max)
        total_i = contact_max;
    std::cout << "|"; 
    this->contacts->output_resize_contact("index");
    std::cout << "|";
    this->contacts->output_resize_contact("first name");
    std::cout << "|";
    this->contacts->output_resize_contact("last name");
    std::cout << "|";
    this->contacts->output_resize_contact("nickname");
    std::cout << "|" << std::endl;
    while (i < total_i)
    {
        this->contacts[i].output_contact(i);
        i++;
    }
}

void    PhoneBook::put_error(std::string errmsg)
{
    std::cerr << errmsg << std::endl;
    std::exit (EXIT_FAILURE);
}
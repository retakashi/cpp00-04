#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{   
}

void    Contact::output_selected_contact()
{
    std::cout << "first name:\n" << this->first_name << "\n";
    std::cout << "last name:\n" << this->last_name << "\n";
    std::cout << "nickname:\n" << this->nickname << "\n";
    std::cout << "phone number:\n" << this->phone_number << "\n";
    std::cout << "darkest secret:\n" << this->darkest_secret << std::endl;  
}

void    Contact::output_resize_contact(std::string field)
{
    if (field.length() > len_max)
    {
        std::cout << field.substr(0, len_max - 1);
        std::cout << ".";
    }
    else
        std::cout << std::right << std::setw(len_max) << field;; 
}

void    Contact::output_contact(int contact_i)
{
    std::cout << "|" << std::right << std::setw(len_max) << contact_i;
    std::cout << "|";
    this->output_resize_contact(this->first_name);
    std::cout << "|";
    this->output_resize_contact(this->last_name);
    std::cout << "|";
    this->output_resize_contact(this->nickname);
    std::cout << "|" << std::endl;
}

void    Contact::set_fields(t_new_fields new_fields)
{
    this->first_name = new_fields.new_first;
    this->last_name = new_fields.new_last;
    this->nickname = new_fields.new_nickname;
    this->phone_number = new_fields.new_number;
    this->darkest_secret = new_fields.new_secret;
}
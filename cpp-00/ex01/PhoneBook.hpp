#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        static const int contact_max = 8;
    public:
        PhoneBook();
        ~PhoneBook();
        std::string get_field(std::string str);
        void    add_contact(int *add_i);
        void    search_contact(int search_i);
        void    output_phonebook(int total_i);
        void    put_error(std::string errmsg);
};

#endif
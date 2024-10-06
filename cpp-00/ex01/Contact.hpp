#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

typedef struct s_new_fields
{
    std::string new_first;
    std::string new_last;
    std::string new_nickname;
    std::string new_number;
    std::string new_secret;
}   t_new_fields;

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        static const int len_max = 10;
    public:
        Contact();
        ~Contact();
        void    output_contact(int contact_i);
        void    output_resize_contact(std::string field);
        void    output_selected_contact();
        void    set_fields(t_new_fields new_fields);
};

#endif
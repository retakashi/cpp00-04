#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string& stringREF = str;

    stringPTR = &str;
    std::cout << "str's pointer: " << &str << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF's pointer: " << &stringREF << std::endl;
    std::cout << "str: " << str << std::endl;
    std::cout << "stringPTR's value: " << *stringPTR << std::endl;
    std::cout << "stringREF's value: " << stringREF << std::endl;
    return (0);
}
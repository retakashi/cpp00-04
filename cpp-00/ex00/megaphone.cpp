#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (argv[i] != NULL)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            std::cout << static_cast<char>(toupper(argv[i][j]));
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return(0);
}
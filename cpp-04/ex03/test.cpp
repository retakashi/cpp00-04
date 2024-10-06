#include <iostream>

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q a.out");
// }
void func(int *a)
{
    a = NULL;
}

int main()
{
    int *arr;
    arr = new int;
    func(arr);
    delete arr;
    return (0);
}
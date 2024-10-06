#include "Harl.hpp"

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q harlFilter");
// }

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid args." << std::endl;
    exit(EXIT_FAILURE);
  }
  Harl harl;
  harl.complain((std::string)argv[1]);
  return 0;
}
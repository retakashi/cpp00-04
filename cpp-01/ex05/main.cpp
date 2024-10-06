#include "Harl.hpp"

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q harl");
// }

int main() {
  std::string level;
  level = "";
  Harl harl;
  harl.complain(level);
  return 0;
}
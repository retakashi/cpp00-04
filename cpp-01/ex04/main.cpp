#include "Replace.hpp"

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q replace");
// }

int main() {
  std::string filename = "a";
  std::string s1 = "apple";
  std::string s2 = "banana";
  Replace rep = Replace(filename, s1, s2);

  rep.replaceS1S2();
  return 0;
}
#include <iostream>

class Harl {
 private:
  void debug();
  void info();
  void warning();
  void error();
  static const int total = 4;
//   std::string level;
  typedef void (Harl::*funcPointer)();

 public:
  Harl();
  ~Harl();
  void complain(std::string level);
};
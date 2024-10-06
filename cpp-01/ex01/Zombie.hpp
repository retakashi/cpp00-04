#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name;
  int zombie_i;

 public:
  Zombie(std::string& name, int i);
  Zombie();
  ~Zombie();
  void announce();
  void set_data(const std::string& new_name, int i);
};

Zombie* zombieHorde(int N, std::string name);
#endif
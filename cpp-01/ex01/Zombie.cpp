#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << this->name << "[" << this->zombie_i << "]"
            << " destroyed." << std::endl;
}

void Zombie::announce() {
  std::cout << this->name << "[" << this->zombie_i << "]"
            << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_data(const std::string& new_name, int i) {
  this->name = new_name;
  this->zombie_i = i;
}

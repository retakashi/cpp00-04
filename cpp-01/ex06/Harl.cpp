#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
  std::cout
      << "[ DEBUG ]\nI love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout
      << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You "
         "didn't put enough bacon in my burger! If you did, I wouldn't be "
         "asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "[ WARNING ]\nI think I deserve to have some extra bacon for free. "
         "I've been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error() {
  std::cout
      << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
      << std::endl;
}

void Harl::complain(std::string level) {
  std::string complaints[total] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i;
  i = 0;
  while (i < total && complaints[i] != level) {
    i++;
  }
  switch (i) {
    case 0:
      this->debug();
    case 1:
      this->info();
    case 2:
      this->warning();
    case 3:
      this->error();
      break;
    default:
      std::cerr << "[ Probably complaining about insignificant problems ]"
                << std::endl;
      break;
  }
}
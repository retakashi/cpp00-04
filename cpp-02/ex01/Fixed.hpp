#include <cmath>
#include <iostream>
#include <string>
class Fixed {
 private:
  int internalFixed;
  static const int bits = 8;

 public:
  Fixed();
  Fixed(int value);
  Fixed(float value);
  ~Fixed();
  Fixed(const Fixed& a);
  Fixed& operator=(const Fixed& c);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);

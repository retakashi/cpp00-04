#include <cmath>
#include <iostream>
#include <string>

//>, <, >=, <=, == and !=
//+, -, *, and /
// num++, ++num , num--, --num
// min, max const
class Fixed
{
private:
  int internalFixed;
  static const int bits = 8;

public:
  Fixed();
  Fixed(int value);
  Fixed(float value);
  ~Fixed();
  Fixed(const Fixed &a);
  Fixed &operator=(const Fixed &c);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  bool operator>(const Fixed &c) const;
  bool operator<(const Fixed &c) const;
  bool operator>=(const Fixed &c) const;
  bool operator<=(const Fixed &c) const;
  bool operator==(const Fixed &c) const;
  bool operator!=(const Fixed &c) const;
  Fixed operator*(const Fixed &c);
  Fixed operator+(const Fixed &c);
  Fixed operator-(const Fixed &c);
  Fixed operator/(const Fixed &c);
  Fixed &operator++(); // pre
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  static Fixed &min(Fixed &c1, Fixed &c2);
  static const Fixed &min(const Fixed &c1, const Fixed &c2);
  static Fixed &max(Fixed &c1, Fixed &c2);
  static const Fixed &max(const Fixed &c1, const Fixed &c2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &c);

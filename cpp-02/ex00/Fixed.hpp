#include <iostream>
#include <string>

class Fixed
{
    private:
        int fixedPointNumber;
        static const int bits = 8;
    public:
    Fixed();
    ~Fixed();
    Fixed( Fixed& a);
    Fixed& operator = ( const Fixed& c );
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
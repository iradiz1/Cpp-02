#pragma once

#include <iostream>

class Fixed{
public:
    Fixed();
    ~Fixed();
    Fixed(Fixed const &copy);
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:
    int fixedpointnbr;
    static const int fractionalbits = 8;
};
#pragma once

# include <iostream>
# include <cmath>

class Fixed{
public:
    Fixed();
    Fixed(const int nbr);
    Fixed(const float nbr);
    Fixed(Fixed const &copy);
    ~Fixed();
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    
private:
    int fixedpointnbr;
    static const int fractionalbits = 8;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);
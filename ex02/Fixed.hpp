#ifndef FIXED_HPP
# define FIXED_HPP

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

    bool operator<(const Fixed &copy) const;
    bool operator>(const Fixed &copy) const;
    bool operator<=(const Fixed &copy) const;
    bool operator>=(const Fixed &copy) const;
    bool operator!=(const Fixed &copy) const;
    bool operator==(const Fixed &copy) const;

    Fixed operator+(const Fixed &copy) const;
    Fixed operator-(const Fixed &copy) const;
    Fixed operator*(const Fixed &copy) const;
    Fixed operator/(const Fixed &copy) const;

    Fixed &operator--();
    Fixed &operator++();
    Fixed operator--(int nbr);
    Fixed operator++(int nbr);

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int fixedpointnbr;
    static const int fractionalbits = 8;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
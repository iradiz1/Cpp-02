#include "Fixed.hpp"

Fixed::Fixed() : fixedpointnbr(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr){
    std::cout << "Int constructor called" << std::endl;
    this->fixedpointnbr = nbr << fractionalbits;
}

Fixed::Fixed(const float nbr) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedpointnbr = roundf(nbr * (1 << fractionalbits));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->fixedpointnbr = copy.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    return (this->fixedpointnbr);
}

void Fixed::setRawBits(int const raw) {
    this->fixedpointnbr = raw;
}

float Fixed::toFloat() const {
    return (float)fixedpointnbr / (1 << fractionalbits);
}

int Fixed::toInt( void ) const {
    return (this->fixedpointnbr >> this->fractionalbits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
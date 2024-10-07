#include "Fixed.hpp"

Fixed::Fixed() : fixedpointnbr(0){
}

Fixed::Fixed(const int nbr){
    this->fixedpointnbr = nbr << fractionalbits;
}

Fixed::Fixed(const float nbr) {
    this->fixedpointnbr = roundf(nbr * (1 << fractionalbits));
}

Fixed::~Fixed(){
}

Fixed::Fixed(Fixed const &copy){
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
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

bool Fixed::operator<(const Fixed &copy) const{
    return this->fixedpointnbr < copy.fixedpointnbr;
}

bool Fixed::operator>(const Fixed &copy) const{
    return this->fixedpointnbr > copy.fixedpointnbr;
}

bool Fixed::operator<=(const Fixed &copy) const{
    return this->fixedpointnbr <= copy.fixedpointnbr;
}

bool Fixed::operator>=(const Fixed &copy) const{
    return this->fixedpointnbr >= copy.fixedpointnbr;
}

bool Fixed::operator!=(const Fixed &copy) const{
    return this->fixedpointnbr != copy.fixedpointnbr;
}

bool Fixed::operator==(const Fixed &copy) const{
    return this->fixedpointnbr == copy.fixedpointnbr;
}

Fixed Fixed::operator+(const Fixed &copy) const{
    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) const{
    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) const{
    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const{
    return Fixed(this->toFloat() / copy.toFloat());
}

Fixed &Fixed::operator++(){
    this->fixedpointnbr++;
    return *this;
}

Fixed &Fixed::operator--(){
    this->fixedpointnbr--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->fixedpointnbr--;
    return temp;
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->fixedpointnbr++;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if (a > b)
        return a;
    return b;
}
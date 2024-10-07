#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( 10 );
    Fixed const d( 42.42f );

    std::cout << "Testing constructors:" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "\nTesting comparison operators:" << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;
    std::cout << "b == b: " << (b == b) << std::endl;
    std::cout << "a != d: " << (a != d) << std::endl;

    std::cout << "\nTesting arithmetic operators:" << std::endl;
    std::cout << "b + c = " << (b + c) << std::endl;
    std::cout << "d - b = " << (d - b) << std::endl;
    std::cout << "c * d = " << (c * d) << std::endl;
    std::cout << "d / c = " << (d / c) << std::endl;

    std::cout << "\nTesting increment and decrement:" << std::endl;
    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "Value of a after post-increment: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "Value of a after post-decrement: " << a << std::endl;

    std::cout << "\nTesting min and max functions:" << std::endl;
    std::cout << "Fixed::min( a, b ): " << Fixed::min( a, b ) << std::endl;
    std::cout << "Fixed::max( a, d ): " << Fixed::max( a, d ) << std::endl;


    return 0;
}

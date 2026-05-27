#include "Fixed.hpp"
Fixed::Fixed() : rawValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called\n";
	rawValue = src.rawValue;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other) {
        this->rawValue = other.rawValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return rawValue;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
    rawValue = raw;
}
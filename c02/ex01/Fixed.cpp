#include "Fixed.hpp"
Fixed::Fixed() : rawValue(0)
{
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->rawValue = value << fractionalBits; //shift all bits to the left by fractionalBits positions = multiply by 2^8
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawValue = roundf(value * (1 << fractionalBits));
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

float Fixed::toFloat(void) const
{
	    return (float)this->rawValue / (float)(1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->rawValue / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
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
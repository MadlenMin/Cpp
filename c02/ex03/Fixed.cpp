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
//Comperison operators 

bool Fixed::operator>(const Fixed& other) const
{
	return this->rawValue > other.rawValue;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->rawValue < other.rawValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->rawValue >= other.rawValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->rawValue <= other.rawValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->rawValue != other.rawValue;
}

//Arithmetic operators 

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->rawValue + other.rawValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->rawValue - other.rawValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long temp = (long long)this->rawValue * other.rawValue;
    result.setRawBits(temp / (1 << fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.rawValue == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    long long temp = (long long)this->rawValue * (1 << fractionalBits);
    result.setRawBits(temp / other.rawValue);
    return result;
}

// increment decrement 

// pre increment ++a 

Fixed& Fixed::operator++()
{
    this->rawValue += 1;
    return *this;
}

// post increment a++
Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->rawValue += 1;
    return old;
}

// pre decrement --a

Fixed& Fixed::operator--()
{
    this->rawValue -= 1;
    return *this;
}

// post decrement

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->rawValue -= 1;
    return old;
}

// min max comperisson 
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.rawValue < b.rawValue) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.rawValue < b.rawValue) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.rawValue > b.rawValue) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.rawValue > b.rawValue) ? a : b;
}


#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int rawValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& other);
		~Fixed(); 

		 int getRawBits( void ) const;
		 void setRawBits( int const raw );

		 float toFloat( void ) const;
   		 int toInt( void ) const;

		bool operator<(const Fixed& other) const;
    	bool operator>(const Fixed& other) const;
    	bool operator<=(const Fixed& other) const;
    	bool operator>=(const Fixed& other) const;
    	bool operator==(const Fixed& other) const;
   	 	bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment and decrement operators
		Fixed& operator++(); // Pre increment returnes a refrence bc it increments a then returnes it/returnes the actuall object
		Fixed operator++(int); //returns a copy, it returns the old value that is about to change 
		Fixed& operator--();
		Fixed operator--(int);

			// Increment and decrement operators
		static Fixed& min(Fixed& a, Fixed& b); // static bc it belongs to the class not an object
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
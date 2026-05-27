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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
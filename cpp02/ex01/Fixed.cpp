#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	fixed_point = other.fixed_point;
	std::cout << "copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		fixed_point = other.fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int raw)
{
	fixed_point = raw << frac_bits;
}

Fixed::Fixed(const float raw)
{
	fixed_point = roundf(raw * (1 << frac_bits));
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point = raw;
}

int Fixed::toInt( void ) const
{
	return fixed_point >> frac_bits;
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point / (1 << frac_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
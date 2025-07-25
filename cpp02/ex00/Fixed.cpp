
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

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		fixed_point = other.fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

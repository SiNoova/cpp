#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const Fixed &other)
{
	fixed_point = other.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		fixed_point = other.fixed_point;
	return *this;
}

Fixed::~Fixed()
{
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
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixed_point < other.fixed_point)
		return true;
	else
		return false;
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixed_point > other.fixed_point)
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixed_point <= other.fixed_point)
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixed_point >= other.fixed_point)
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixed_point == other.fixed_point)
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixed_point != other.fixed_point)
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixed_point + other.fixed_point);
	return result;
}


Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixed_point - other.fixed_point);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->fixed_point * other.fixed_point) >> frac_bits);
    return result;
}


Fixed Fixed::operator/(const Fixed &other) const
{
	if (!other.fixed_point)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	Fixed result;
	result.setRawBits((this->fixed_point << frac_bits) / other.fixed_point);
	return result;
}


Fixed& Fixed::operator++()
{
	this->fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_point++;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_point--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

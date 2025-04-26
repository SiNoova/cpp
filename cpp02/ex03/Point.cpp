#include "Point.hpp"
#include "Fixed.hpp"


Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Fixed a, const Fixed b) : x(a), y(b) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
    std::cout << "Assignment operator called, but x and y are const — nothing assigned." << std::endl;
    return *this;
}

Point::~Point() {}

const Fixed &Point::getX() const
{
    return x;
}

const Fixed &Point::getY() const
{
    return y;
}

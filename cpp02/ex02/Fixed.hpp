#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator<(const Fixed &other) const ;
		bool operator>(const Fixed &other) const ; 
		bool operator<=(const Fixed &other) const ;
		bool operator>=(const Fixed &other) const ;
		bool operator==(const Fixed &other) const ;
		bool operator!=(const Fixed &other) const ;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif
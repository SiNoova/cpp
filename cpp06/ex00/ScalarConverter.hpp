#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <sstream> 
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const&);
		ScalarConverter& operator=(ScalarConverter const&);
		~ScalarConverter();
	public:
		static void convert(const std::string &literal);
};

#endif
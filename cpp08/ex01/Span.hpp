#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

class Span
{
	private:
		unsigned int N;
		std::vector<int> intergers;
	public:
		Span();
		Span(unsigned int new_n);
		void addNumber(const int new_number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		~Span();
};

#endif
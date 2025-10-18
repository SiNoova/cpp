#include "Span.hpp"

Span::Span() : N(0), intergers() {}

Span::Span(unsigned int new_n) : N(new_n), intergers() {}

Span::Span(const Span &other) : N(other.N), intergers(other.intergers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		intergers = other.intergers;
	}
	return *this;
}

void Span::addNumber(const int new_number)
{
	if (intergers.size() >= N)
		throw std::runtime_error("can't add more numbers to the vector: not enough space!");
	intergers.push_back(new_number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (intergers.size() + std::distance(begin, end) > N)
        throw std::runtime_error("Not enough space to add range of numbers");
    intergers.insert(intergers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (intergers.size() < 2)
		throw std::runtime_error("not enough numbersd to find a span");

	std::vector<int> sorted = intergers;
	int min = std::numeric_limits<int>::max();
	std::sort(sorted.begin(), sorted.end());
	
	for (size_t i = 1; i < sorted.size(); i++)
		min = std::min(min, sorted[i] - sorted[i - 1]);
	return min;
}

int Span::longestSpan()
{
	if (intergers.size() < 2)
		throw std::runtime_error("not enough numbersd to find a span");

	unsigned int min = *std::min_element(intergers.begin(), intergers.end());
	unsigned int max = *std::max_element(intergers.begin(), intergers.end());
	return max - min;
}

Span::~Span() {}
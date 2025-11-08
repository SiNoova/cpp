#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	getline(file, line);

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, rateStr;
		if (getline(ss, date, ',') && getline(ss, rateStr))
		{
			float rate = atof(rateStr.c_str());
			databise[date] = rate;
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : databise(other.databise) {}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->databise = other.databise;
	}
	return *this;
}

void parse_date(std::string date)
{

}

void BitcoinExchange::ProcessInput(const char *input_path)
{
	std::ifstream file(input_path);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	getline(file, line);

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, rateStr;
		if (getline(ss, date, '|') && getline(ss, rateStr))
		{
			float rate = atof(rateStr.c_str());
			databise[date] = rate;
		}
	}
}



BitcoinExchange::~BitcoinExchange() {}
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

bool parse_date(std::string &date)
{
	int year, month, day;
    char dash1, dash2;

	std::cout << date << std::endl;
	 if (date.size() != 11 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
	{
        if ((i != 4 && i != 7) && !std::isdigit(date[i]))
            return false;
    }

	std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (dash1 != '-' || dash2 != '-')
        return false;
    std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
	return true;
}

void BitcoinExchange::ProcessInput(const char *input_path)
{
	std::ifstream file(input_path);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;
	if	(std::getline(file, line))
	{
		if (line != "date | value")
		{
			std::cerr << "Invalid header in input file date | value" << std::endl;
            return ;
		}
	}

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, rateStr;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (getline(ss, date, '|') && getline(ss, rateStr))
		{
			parse_date(date);
		}
	}
}



BitcoinExchange::~BitcoinExchange() {}
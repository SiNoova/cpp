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
	file.close();
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

	 if (date.size() != 10 || date[4] != '-' || date[7] != '-')
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
	else if (month < 1 || month > 12)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2)
	{
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1])
        return false;
	else
		return true;
}

bool parse_value(std::string &value)
{
	int count = 0;
	if (value[0] == '-')
    {
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
	for (size_t i = 0; i < value.size(); i++)
	{
		if ((i == 0 && value[i] == '.') || (i == value.size() - 1 && value[i] == '.'))
		{
			std::cout << "Not a number!" << std::endl;
			return false;
		}
		if (value[i] == '.')
			count++;
		else if (!std::isdigit(value[i]))
		{
			std::cout << "Not a number!" << std::endl;
			return false;
		}
	}
	if (count > 1)
	{
		std::cout << "Not a number!" << std::endl;
		return false;
	}
	std::stringstream ss(value);
	int num;
	ss >> num;
	if (ss.fail() || num > 1000 || num < 0)
    {
        std::cout << "Error: too large a number." << std::endl;
		return false;
    }
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
			std::cout << "Error: Invalid header in input file date | value" << std::endl;
            return ;
		}
	}

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, value;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		getline(ss, date, '|');
		size_t first = date.find_first_not_of(" \t");
		size_t last = date.find_last_not_of(" \t");
		if (date.empty() || first == std::string::npos || last == std::string::npos)
		{
			std::cout << "Error: Missing date" << std::endl;
			continue;
		}
		date = date.substr(first, (last - first + 1));

		if (!parse_date(date))
		{
			std::cout << "Error: Invalid date!" << std::endl;
			continue;
		}
		std::getline(ss, value);
		size_t first_value = value.find_first_not_of(" \t");
        size_t last_value = value.find_last_not_of(" \t");
		if (value.empty() || first_value  == std::string::npos || last_value  == std::string::npos) 
		{
			std::cout << "Error: Missing value" << std::endl;
			continue;
		}
        value = value.substr(first_value, (last_value - first_value + 1));
		if (!parse_value(value))
			continue;
		float f_value;
        std::stringstream sss(value);
        sss >> f_value;
		std::map<std::string, float>::iterator it = databise.lower_bound(date);
		 if (it != databise.end() && it->first == date)
			std::cout << date << " => " << f_value << " = " << f_value * it->second << std::endl;
		else
		{
			if (it != databise.begin())
			{
				it--;
				if (it->first < date)
					std::cout << date << " => " << f_value << " = " << it->second * f_value << std::endl;
				else
					std::cerr << "No date found in the data.csv for: " << date << std::endl;
			}
			else
				std::cerr << "No date found in the data.csv for: " << date << std::endl;
		}
	}
	file.close();
}



BitcoinExchange::~BitcoinExchange() {}
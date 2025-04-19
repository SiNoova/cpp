#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "invalid args!!" << std::endl;
		return 1;
	}

	std::string file(av[1]);
	std::ifstream infile(file.c_str());
	std::ofstream oufile((file + ".replace").c_str());
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string line;
	size_t index = 0;

	if (!infile)
	{ 
		std::cerr << "Error opening file!" << std::endl;
		return 1; 
    }
    while (std::getline(infile, line))
	{
		while (!s1.empty())
		{
			index = line.find(s1, index);
			if (index != std::string::npos)
			{
				line.erase(index, s1.length());
				line.insert(index, s2);
			}
			else
				break;
			index += s2.length();
		}
        oufile << line;
		if (!infile.eof())
			oufile << std::endl;
		index = 0;
    }
}


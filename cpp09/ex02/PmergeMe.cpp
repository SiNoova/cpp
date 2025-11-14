#include "PmergeMe.hpp"

size_t generate_jakobstald_number(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	return 2 * generate_jakobstald_number(n - 1) + n % 2 == 0 ? 1 : -1;
}

int generate_number(int n)
{
	return pow(2, n + 1) - 1;
}

void generate_jakobstald_sequence(std::vector<int> &sequence,std::vector<int> &origin,std::vector<std::string> &flags,size_t size)
{
	int prev = 1;
	int curr = 1;
	for (size_t i = 1; generate_jakobstald_number(i) <= size; i++)
	{
		if (i == 1)
		{
			sequence.push_back(1);
			origin.push_back(1);
			flags.push_back("yes");
			continue;
		}
		curr = generate_jakobstald_number(i);
		origin.push_back(curr);
		flags.push_back("yes");
		int curr2 = curr;
		sequence.push_back(curr2);
		while (--curr2 > prev)
		{
			sequence.push_back(curr2);
			flags.push_back("no");
		}
		prev = curr;
	}
	while (sequence.size() != size)
	{
		curr++;
		sequence.push_back(curr);
		flags.push_back("no");
	}
	
}


void generate_size(std::vector<int> &sequence, size_t size)
{
	for (size_t i = 0; i < size; i++)
		sequence.push_back(generate_number(i));
}

std::vector<int> sorting(std::vector<int> vect, size_t level)
{
	std::vector<std::vector<int> >main, pend;
	std::vector<int> sorted;
	size_t i = 0;
	while (i < vect.size())
	{
		std::vector<int> insertion;
		if (i + level > vect.size())
			break;
		insertion.insert(insertion.begin(), vect.begin() + i, vect.begin() + i + level);
		pend.push_back(insertion);
		i += level;
		if (i < vect.size())
		{
			insertion.clear();
			if (i + level > vect.size())
				break;
			insertion.insert(insertion.begin(), vect.begin() + i, vect.begin() + i + level);
			main.push_back(insertion);
			i += level;
		}
	}
	if (!pend.empty())
		main.insert(main.begin(), pend[0]);
	if (pend.size() > 1)
	{
		std::vector<int> jak_vec;
		std::vector<int> origin;
		std::vector<std::string> flags;
		std::vector<int> v_size;
		size_t k = 1;
		generate_jakobstald_sequence(jak_vec, origin, flags, pend.size());
		generate_size(v_size, origin.size());
		int right;
		for (size_t i = 1; i < jak_vec.size(); i++)
		{
			int left = 0;
			if (flags[i] == "yes")
			{
				right = v_size[k];
				k++;
			} 
			if (k >= v_size.size())
				right = main.size();
			int right2 = right;
			while (left < right2)
			{
				int middle =  left + (right2 - left) / 2;
				if (pend[jak_vec[i] - 1].back() < main[middle].back())
					right2 = middle;
				else
					left = middle + 1;
			}
			main.insert(main.begin() + left, pend[jak_vec[i] - 1]);
		}
	}
	for (size_t i = 0; i < main.size(); i++)
		sorted.insert(sorted.end(), main[i].begin(), main[i].end());
	for (size_t i = sorted.size(); i < vect.size(); i++)
		sorted.push_back(vect[i]);
	return sorted;
}

std::vector<int> pairing(std::vector<int> vect, size_t level)
{
	if (level > 1 && level > vect.size() / 2)
		return vect;
	std::vector<int> new_vec;
	for (size_t i = 0 ; i < vect.size(); i += 2 * level)
	{
		std::vector<int> pair1;
		std::vector<int> pair2;
		for (size_t j = i; j < level + i  && j < vect.size(); j++)
		{
			pair1.push_back(vect[j]);
		}
		for (size_t j = i + level ; j < level * 2 + i && j < vect.size(); j++)
			pair2.push_back(vect[j]);
		if (pair1.size() == level && pair2.size() == level && pair1.back() <= pair2.back())
		{
			new_vec.insert(new_vec.end(), pair1.begin(), pair1.end());
			new_vec.insert(new_vec.end(), pair2.begin(), pair2.end());
		}
		else if (pair1.size() == level && pair2.size() == level&& pair2.back() < pair1.back())
		{
			new_vec.insert(new_vec.end(), pair2.begin(), pair2.end());
			new_vec.insert(new_vec.end(), pair1.begin(), pair1.end());
		}
		pair1.clear();
		pair2.clear();
	}
	for (size_t i = new_vec.size(); i < vect.size(); i++)
		new_vec.push_back(vect[i]);

	new_vec = pairing(new_vec, level * 2);
	new_vec = sorting(new_vec, level);
	return new_vec;
}

void generate_jakobstald_sequence(std::deque<int> &sequence,std::deque<int> &origin,std::deque<std::string> &flags,size_t size)
{
	int prev = 1;
	int curr = 1;
	for (int i = 1; generate_jakobstald_number(i) <= size; i++)
	{
		if (i == 1)
		{
			sequence.push_back(1);
			origin.push_back(1);
			flags.push_back("yes");
			continue;
		}
		curr = generate_jakobstald_number(i);
		origin.push_back(curr);
		flags.push_back("yes");
		int curr2 = curr;
		sequence.push_back(curr2);
		while (--curr2 > prev)
		{
			sequence.push_back(curr2);
			flags.push_back("no");
		}
		prev = curr;
	}
	while (sequence.size() != size)
	{
		curr++;
		sequence.push_back(curr);
		flags.push_back("no");
	}
	
}


void generate_size(std::deque<int> &sequence, size_t size)
{
	for (size_t i = 0; i < size; i++)
		sequence.push_back(generate_number(i));
}

std::deque<int> sorting(std::deque<int> vect, size_t level)
{
	std::deque<std::deque<int> >main, pend;
	std::deque<int> sorted;
	size_t i = 0;
	while (i < vect.size())
	{
		std::deque<int> insertion;
		if (i + level > vect.size())
			break;
		insertion.insert(insertion.begin(), vect.begin() + i, vect.begin() + i + level);
		pend.push_back(insertion);
		i += level;
		if (i < vect.size())
		{
			insertion.clear();
			if (i + level > vect.size())
				break;
			insertion.insert(insertion.begin(), vect.begin() + i, vect.begin() + i + level);
			main.push_back(insertion);
			i += level;
		}
	}
	if (!pend.empty())
		main.insert(main.begin(), pend[0]);
	if (pend.size() > 1)
	{
		std::deque<int> jak_vec;
		std::deque<int> origin;
		std::deque<std::string> flags;
		std::deque<int> v_size;
		size_t k = 1;
		generate_jakobstald_sequence(jak_vec, origin, flags, pend.size());
		generate_size(v_size, origin.size());
		int right;
		for (size_t i = 1; i < jak_vec.size(); i++)
		{
			int left = 0;
			if (flags[i] == "yes")
			{
				right = v_size[k];
				k++;
			} 
			if (k >= v_size.size())
				right = main.size();
			int right2 = right;
			while (left < right2)
			{
				int middle =  left + (right2 - left) / 2;
				if (pend[jak_vec[i] - 1].back() < main[middle].back())
					right2 = middle;
				else
					left = middle + 1;
			}
			main.insert(main.begin() + left, pend[jak_vec[i] - 1]);
		}
	}
	for (size_t i = 0; i < main.size(); i++)
		sorted.insert(sorted.end(), main[i].begin(), main[i].end());
	for (size_t i = sorted.size(); i < vect.size(); i++)
		sorted.push_back(vect[i]);
	return sorted;
}

std::deque<int> pairing(std::deque<int> vect, size_t level)
{
	if (level > 1 && level > vect.size() / 2)
		return vect;
	std::deque<int> new_vec;
	for (size_t i = 0 ; i < vect.size(); i += 2 * level)
	{
		std::deque<int> pair1;
		std::deque<int> pair2;
		for (size_t j = i; j < level + i  && j < vect.size(); j++)
		{
			pair1.push_back(vect[j]);
		}
		for (size_t j = i + level ; j < level * 2 + i && j < vect.size(); j++)
			pair2.push_back(vect[j]);
		if (pair1.size() == level && pair2.size() == level && pair1.back() <= pair2.back())
		{
			new_vec.insert(new_vec.end(), pair1.begin(), pair1.end());
			new_vec.insert(new_vec.end(), pair2.begin(), pair2.end());
		}
		else if (pair1.size() == level && pair2.size() == level&& pair2.back() < pair1.back())
		{
			new_vec.insert(new_vec.end(), pair2.begin(), pair2.end());
			new_vec.insert(new_vec.end(), pair1.begin(), pair1.end());
		}
		pair1.clear();
		pair2.clear();
	}
	for (size_t i = new_vec.size(); i < vect.size(); i++)
		new_vec.push_back(vect[i]);

	new_vec = pairing(new_vec, level * 2);
	new_vec = sorting(new_vec, level);
	return new_vec;
}


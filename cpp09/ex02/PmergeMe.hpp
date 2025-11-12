#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
class PmergeMe
{

	public:
		static std::vector<int> &merge_sort(std::vector<int> vect);
};

std::vector<int> pairing(std::vector<int> vect, size_t level);
int isitsorted(std::vector<int> vect);
int generate_jakobstald_number(int n);
void generate_jakobstald_sequence(std::vector<int> &sequence, size_t size);
#endif
#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <deque>

std::vector<int> pairing(std::vector<int> vect, size_t level);
std::deque<int> pairing(std::deque<int> vect, size_t level);
size_t generate_jakobstald_number(int n);
void generate_jakobstald_sequence(std::vector<int> &sequence, size_t size);
#endif
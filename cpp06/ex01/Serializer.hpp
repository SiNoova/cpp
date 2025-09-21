#ifndef SERILIZER_HPP
#define SERILIZER_HPP

#include <iostream>
#include <stdint.h> // Include for uintptr_t


typedef struct s_Data {
	int x;
	short a;
	double j;
} Data;


class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const&);
		Serializer& operator=(Serializer const&);
		~Serializer(void);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &) {}

Serializer& Serializer::operator=(Serializer const &)
{
	return *this;
}

Serializer::~Serializer(void) {}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;

}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* result = reinterpret_cast<Data *>(raw);
	return result;
}
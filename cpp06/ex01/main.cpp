#include "Serializer.hpp"

int main(int argc, char **argv)
{
	Data result = {54, 3, 8.6};
	Data *result_ptr = &result;
	
	std::cout << "The original Data contains: " << std::endl;
	std::cout << "int: " << result.x << std::endl;
	std::cout << "short: "<< result.a << std::endl;
	std::cout << "double: "<< result.j << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	unsigned long result_uintptr = Serializer::serialize(result_ptr);
	std::cout << "result_uintptr: " << result_uintptr << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	Data *result_data = Serializer::deserialize(result_uintptr);
	std::cout << "result_data contains: "  << std::endl;
	std::cout << "int: " << result_data->x << std::endl;
	std::cout << "short: "<< result_data->a << std::endl;
	std::cout << "double: "<< result_data->j << std::endl;
}
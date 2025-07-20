#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat john("John", 42);
		std::cout << john << std::endl;

		john.IncrementGrade();
		std::cout << "After increment: " << john << std::endl;

		john.DecrementGrade();
		std::cout << "After decrement: " << john << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try {
		Bureaucrat alice("Alice", 0);
	}
	catch (std::exception &e) {
		std::cerr << "Exception when creating Alice: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try {
		Bureaucrat bob("Bob", 151); 
	}
	catch (std::exception &e) {
		std::cerr << "Exception when creating Bob: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try {
		Bureaucrat top("TopGuy", 1);
		std::cout << top << std::endl;
		top.IncrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << "Exception on increment: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;
	try {
		Bureaucrat low("LowGuy", 150);
		std::cout << low << std::endl;
		low.DecrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << "Exception on decrement: " << e.what() << std::endl;
	}

	return 0;
}

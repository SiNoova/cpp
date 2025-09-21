#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int	random_pick;
	std::srand(time(0));
	random_pick  = std::rand() % 3;
	if (random_pick == 0){
		std::cout << "Generated A" << std::endl;
		return new A;
	}
	else if (random_pick == 1){
		std::cout << "Generated B" << std::endl;
		return new B;
	}
	else{
		std::cout << "Generated C" << std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Invalid Type!" << std::endl;
}

void identify(Base& p)
{
	Base &check = p;
	try
	{
		check = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e) {}
	try
	{
		check = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception & e) {}
	try
	{
		check = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception & e) {}
}


int main(){
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;
}
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {(void)other;}

RPN &RPN::operator=(const RPN &other) {(void)other;return *this;}

int is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::Reverse_polish_notaion(std::string &str)
{
	std::stack<int> stack;
	std::stringstream ss(str);
	std::string s;

	while (ss >> s)
	{
		if (s.size() == 1 && std::isdigit(s[0]))
			stack.push(s[0] - 48);
		else if (s.size() == 1 && is_operator(s[0]) && stack.size() >= 2)
		{
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (s[0] == '+')
				stack.push(a + b);
			if (s[0] == '-')
				stack.push(a - b);
			if (s[0] == '*')
				stack.push(a * b);
			if (s[0] == '/')
				stack.push(a / b);
		}
		else
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
	
}

RPN::~RPN() {}
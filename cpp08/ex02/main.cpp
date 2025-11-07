#include "MutantStack.hpp"

<<<<<<< HEAD
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << "\n--- Forward iteration ---" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n--- Reverse iteration ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n--- Const iteration ---" << std::endl;
    const MutantStack<int> constStack = mstack;
    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\nCopying into std::stack:" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Top element of std::stack: " << s.top() << std::endl;
=======
int main() {
	std::cout << "std::list ------------------------------" << std::endl;
	{
		std::list<int> intList;
		intList.push_back(1);
		intList.push_back(2);
		intList.push_back(1337);
		std::cout << "intList.back(): " << intList.back() << std::endl;
		intList.pop_back();
		std::cout << "intList.size(): " << intList.size() << std::endl;
		intList.push_back(3);
		intList.push_back(4);
		intList.push_back(5);
		intList.push_back(6);

		std::list<int>::iterator listIt = intList.begin();
		std::list<int>::iterator listEnd = intList.end();
		++listIt;
		--listIt;
		while (listIt != listEnd)
		{
			std::cout << *listIt << std::endl;
			++listIt;
		}

		std::list<int> copiedList(intList);
		std::list<int>::reverse_iterator listRevIt;
		std::cout << "rbegin: " << *copiedList.rbegin() << std::endl;
		std::cout << "rend: " << *(--copiedList.rend()) << std::endl;
		std::cout << "Content: " << std::endl;
		for (listRevIt = --copiedList.rend(); listRevIt != --copiedList.rbegin(); listRevIt--){
			std::cout << *listRevIt << std::endl;
		}
	}

	std::cout << "MutantStack ------------------------------" << std::endl;
	{
		MutantStack<int> mStack;
		mStack.push(1);
		mStack.push(2);
		mStack.push(1337);
		std::cout << "mStack.top(): " << mStack.top() << std::endl;
		mStack.pop();
		std::cout << "mStack.size(): " << mStack.size() << std::endl;
		mStack.push(3);
		mStack.push(4);
		mStack.push(5);
		mStack.push(6);

		MutantStack<int>::iterator stackIt = mStack.begin();
		MutantStack<int>::iterator stackEnd = mStack.end();
		++stackIt;
		--stackIt;
		while (stackIt != stackEnd)
		{
			std::cout << *stackIt << std::endl;
			++stackIt;
		}

		std::stack<int> standardStack(mStack);
		MutantStack<int> copiedStack(mStack);
		MutantStack<int>::reverse_iterator stackRevIt;
		std::cout << "rbegin: " << *copiedStack.rbegin() << std::endl;
		std::cout << "rend: " << *(--copiedStack.rend()) << std::endl;
		std::cout << "Content: " << std::endl;
		for (stackRevIt = --copiedStack.rend(); stackRevIt != --copiedStack.rbegin(); stackRevIt--){
			std::cout << *stackRevIt << std::endl;
		}
	}
	return 0;
>>>>>>> bd1450b7ccdfdd4d684b2972861526ca03464cca

}

#ifndef  ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T* arr;
		size_t len;
	public:
		Array() : arr(NULL), len(0) {};
		Array(unsigned int n)
		{
			arr = new T[n]();
			len = n;	
		};
		Array(const Array& other)
		{
			arr = new T[other.len]();
			len = other.len;
			for (size_t i = 0; i < len; i++)
				arr[i] = other.arr[i];
		};
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete [] arr;
				arr = new T[other.len]();
				len = other.len;
				for (size_t i = 0; i < len; i++)
					arr[i] = other.arr[i];
			}
			return *this;
		};
		T& operator[](size_t i)
		{
			if (i >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[i];
		}
		const T& operator[](size_t i) const
 		{
			if (i >= len)
				throw std::out_of_range("Index out of bounds");
			return arr[i];
		}
		size_t size() const 
		{
			return len;
		};
		~Array()
		{
			delete [] arr;
		};
};

#endif
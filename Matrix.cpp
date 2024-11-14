#include "Matrix.h"
#include <initializer_list>

/*
template<class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init)
{
	for (const std::initializer_list<T>& row : init) 
	{
		_MX.push_back(std::vector<T>(row));
	}
}


template<typename T>
void Matrix<T>::print() const
{
	for (const auto& row : _MX)
	{
		std::cout << "| ";
		for (const auto& elem : row)
		{
			std::cout << elem << " ";
		}
		std::cout << "|" << "\n";
	}
}
*/
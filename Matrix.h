#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <initializer_list>
#include <iostream>


template <class T>
void printV(std::vector<T> vec)
{
	std::cout << "{ ";
	for (const T x : vec)
	{
		std::cout << x << " ";
	}
	std::cout << "}" << std::endl;
}


template<typename T>
class Matrix {
private:

	std::vector<std::vector<T>> _MX;

public:

	Matrix(std::initializer_list<std::initializer_list<T>> init)
	{
		for (const std::initializer_list<T>& row : init)
		{
			_MX.push_back(std::vector<T>(row));
		}
	}


	std::vector<T> get_row(int row)
	{
		if (0 <= row && row < _MX.size()) 
		{
			return _MX[row];
		}
		else 
		{
			throw std::invalid_argument("row out range");
		}
	}


	std::vector<T> get_colum(int row)
	{
		if (0 <= row && row < _MX[0].size())
		{
			std::vector<T> temporal_v;

			for (std::vector<T>& elem : _MX)
			{
				temporal_v.push_back(elem[row]);
			}
			return temporal_v;
		}
		else
		{
			throw std::invalid_argument("colum out range");
		}
	}


	void transpose()
	{
		size_t col = _MX[0].size();
		std::vector<std::vector<T>> new_matrix;
		std::vector<T> temporal_v;

		for (size_t i = 0; i < col; i++)
		{
			for (std::vector<T> x : _MX)
			{
				temporal_v.push_back(x[i]);
			}
			new_matrix.push_back(temporal_v);

			temporal_v.clear();
		}
		_MX = new_matrix;
	}


	void printM() const
	{
		std::cout << "{\n";
		for (const auto& row : _MX)
		{
			std::cout << "  { ";
			for (const auto& elem : row)
			{
				std::cout << elem << " ";
			}
			std::cout << "}" << "\n";
		}
		std::cout << "}\n";
	}
};

#endif // MATRIX_H

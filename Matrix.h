#ifndef Matrix_H
#define Matrix_H


/*
#include<vector>
#include <initializer_list>

template<class T>
class Matrix
{
	std::vector<std::vector<T>> _MX;
	std::pair<int, int> _size;

public:
	Matrix(std::vector<std::vector<T>>& a);

	void change(std::pair<int, int> xy, T a)
	{
		_MX[xy.first()][xy.second()] = a;
	};

	void transpon() 
	{
		std::vector<std::vector<T>> a;
		for (size_t i = 0; i < _size.first(); i++) {
			for (size_t j = 0; j < _size.second(); j++) {
				a[i][j] = _MX[j][i];
			}
		}
		this->_MX = a;
		delete a;
	};

	std::vector<T> get_line(size_t i) const
	{
		return _MX[i];
	}

	vector<vector<T>> get_lines(pair xy) 
	{
		vector<vector<T>> a;
		for (size_t i = xy.first(); i < xy.second(); i++) {
			a += _MX[i]
		}
		return a;
	};
	Matrix sum(Matrix b) 
	{
		vector<vector<T>> a;
		for (size_t i = 0; i < _size.first(); i++) {
			for (size_t j = 0; j < _size.second(); j++) {
				a[i][j] = _MX[i][j] + b[i][j];
			}
		}
		return a;
	};
	Matrix prod_const(T a) 
	{
		vector<vector<T>> b;
		for (size_t i = 0; i < _size.first(); i++) {
			for (size_t j = 0; j < _size.second(); j++) {
				b[i][j] = _MX[i][j] * a;
			}
		}
		return b;
	}

	Matrix prod(Matrix b) {
		vector<vector<T>> a;
		T sum;
		Matrix k = b.transpon();
		for (size_t i = 0; i < _size.first(); i++) {							  work in progress
			for (size_t j = 0; j < _size.second(); j++) {
				sum += _MX[i][j] * k[i][j];
			}
		}
		return a;
	}
};
*/

#include <vector>
#include <initializer_list>
#include <iostream>

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


	void printM() const
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
};

#endif // MATRIX_H

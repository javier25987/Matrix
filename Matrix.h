#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <initializer_list>
#include <iostream>
#include <cmath>
#include "fraction.h"


template <class T>
void printV(std::vector<T> vec)
{
	std::cout << "[ ";
	for (const T x : vec)
	{
		std::cout << x << " ";
	}
	std::cout << "]" << std::endl;
}

template <class T>
bool all_is_zero(std::vector<T> vec)
{
	for (T x : vec)
	{
		if (std::abs(x) > 1e-9) { return false; }
	}
	return true;
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


	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat)
	{
		mat.printM();
		return os;
	}


	// ==========  here is javier's work


	size_t rang() const
	{
		size_t rows = _MX.size();
		size_t cols = _MX[0].size();

		std::vector<std::vector<double>> matrix;
		
		if (rows > cols)
		{
			std::vector<double> temporal_v;

			for (size_t i = 0; i < cols; i++)
			{
				for (auto x : _MX)
				{
					temporal_v.push_back((double)x[i]);
				}

				matrix.push_back(temporal_v);
				temporal_v.clear();
			}
			std::swap(rows, cols);
		}
		else
		{
			std::vector<double> temp;
			for (size_t i = 0; i < _MX.size(); i++)
			{
				for (size_t j = 0; j < _MX[0].size(); j++)
				{
					temp.push_back((double)_MX[i][j]);
				}
				matrix.push_back(temp);
				temp.clear();
			}
		}

		int v_ind = 0, h_ind = 0;
		bool colum_is_cero = false;
		double factor, pivot;

		while (v_ind < rows && h_ind < cols)
		{
			if (std::abs(matrix[v_ind][h_ind]) < 1e-9)
			{
				if (all_is_zero(matrix[v_ind]))
				{
					std::swap(matrix[v_ind], matrix[rows - 1]);
					rows--;
					continue;
				}
				else
				{
					colum_is_cero = true;
					for (int i = v_ind + 1; i < rows; i++)
					{
						if (std::abs(matrix[i][h_ind]) > 1e-9)
						{
							std::swap(matrix[v_ind], matrix[i]);
							colum_is_cero = false;
							break;
						}
					}
					if (colum_is_cero)
					{
						h_ind++;
						colum_is_cero = false;
						continue;
					}
				}
			}
			
			pivot = matrix[v_ind][h_ind];

			for (int i = v_ind + 1; i < rows; i++) 
			{
				factor = matrix[i][h_ind] / pivot;

				for (int j = h_ind; j < cols; j++) 
				{
					matrix[i][j] -= factor * matrix[v_ind][j];
				}
			}
			v_ind++;
			h_ind++;
		}
		return rows;
	}

	/*
	double det() const
	{
		size_t rows = _MX.size();
		size_t cols = _MX[0].size();

		if (rows != cols)
		{
			throw std::invalid_argument("not posible calculate DET");
		}

		std::vector<std::vector<T>> matrix = _MX;

		bool colum_is_cero = false;
		double factor, pivot;

		for (size_t loc = 0; loc < rows; loc++)
		{
			if (std::abs(matrix[loc][loc]) < 1e-9)
			{
				if (all_is_zero(matrix[loc]))
				{
					return 0.0;
				}
				else
				{
					colum_is_cero = true;
					for (int i = loc + 1; i < rows; i++)
					{
						if (std::abs(matrix[i][loc]) > 1e-9)
						{
							std::swap(matrix[loc], matrix[i]);
							colum_is_cero = false;
							break;
						}
					}
					if (colum_is_cero)
					{
						return 0.0;
					}
				}
			}

			pivot = matrix[loc][loc];

			for (size_t i = loc + 1; i < rows; i++)
			{
				factor = matrix[i][loc] / pivot;

				for (size_t j = loc; j < cols; j++)
				{
					matrix[i][j] -= factor * matrix[loc][j];
				}
			}

			std::cout << "---\n";

			for (auto x : matrix)
			{
				printV(x);
			}
		}

		double result = 1.0;
		for (size_t loc = 0; loc < rows; loc++)
		{
			result *= matrix[loc][loc];
		}
		return result;
	}
	*/


	size_t get_cols()  const
	{
		return _MX[0].size();
	}


	// ==========  here is ilia's work


	//vector(vector(T))
	Matrix(std::vector<std::vector<T>> init)
	{
		_MX = init;
	}


	//get count row
	size_t get_rows()  const
	{
		return _MX.size();
	}


	// ��� �������� � (�, �)
	T& operator()(const unsigned& rowNo, const unsigned& colNo)
	{
		return _MX[rowNo][colNo];
	}


	// ����� ���� ������
	Matrix operator+(Matrix& B)
	{
		std::vector<std::vector<T>> sum;
		std::vector<T> tmp;
		unsigned i, j;
		for (i = 0; i < _MX.size(); i++)
		{
			for (j = 0; j < _MX[0].size(); j++)
			{
				tmp.push_back(_MX[i][j] + B(i, j));
			}
			sum.push_back(tmp);
			tmp.clear();
		}
		return sum;
	}

	// �������� ���� ������
	Matrix operator-(Matrix& B) 
	{
		std::vector<std::vector<T>> diff;
		std::vector<T> tmp;
		unsigned i, j;
		for (i = 0; i < _MX.size(); i++)
		{
			for (j = 0; j < _MX[0].size(); j++)
			{
				tmp.push_back(_MX[i][j] - B(i, j));
			}
			diff.push_back(tmp);
			tmp.clear();
		}
		return diff;
	}

	// ��������� ������
	Matrix operator*(Matrix& B) 
	{
		std::vector<std::vector<T>> multip;

		if (_MX[0].size() == B.get_rows())
		{
			std::vector<T> tmp;
			T temp = 0.0;
			for (size_t i = 0; i < _MX.size(); i++)
			{
				for (size_t j = 0; j < _MX[0].size(); j++)
				{
					temp = 0.0;
					for (size_t k = 0; k < _MX[0].size(); k++)
					{
						temp += _MX[i][k] * B(k, j);
					}
					tmp.push_back(temp);
				}
				multip.push_back(tmp);
				tmp.clear();
			}
		}
		else
		{
			std::cout << "Error" << std::endl;
			//  std::assert(true == false);
		}

		return multip;
	}


	// �������� ���������
	Matrix operator+(T scalar) 
	{
		std::vector<std::vector<T>> result;
		std::vector<T> tmp;
		unsigned i, j;
		for (i = 0; i < _MX.size(); i++)
		{
			for (j = 0; j < _MX[0].size(); j++)
			{
				tmp.push_back(_MX[i][j] + scalar);
			}
			result.push_back(tmp);
			tmp.clear();
		}
		return result;
	}


	// ������� ���������
	Matrix operator-(T scalar) 
	{
		std::vector<std::vector<T>> result;
		std::vector<T> tmp;
		unsigned i, j;
		for (i = 0; i < _MX.size(); i++)
		{
			for (j = 0; j < _MX[0].size(); j++)
			{
				tmp.push_back(_MX[i][j] - scalar);
			}
			result.push_back(tmp);
			tmp.clear();
		}
		return result;
	}


	// �������� �� ���������
	Matrix operator*(T scalar) 
	{
		std::vector<std::vector<T>> result;
		std::vector<T> tmp;
		for (size_t i = 0; i < _MX.size(); i++)
		{
			for (size_t j = 0; j < _MX[0].size(); j++)
			{
				tmp.push_back(_MX[i][j] * scalar);
			}
			result.push_back(tmp);
			tmp.clear();
		}
		return result;
	}


	// �������� �� ���������
	Matrix operator/(T scalar) 
	{
		std::vector<std::vector<T>> result = _MX;
		for (size_t i = 0; i < _MX.size(); i++)
		{
			for (size_t j = 0; j < _MX[0].size(); j++)
			{
				result[i][j] /= scalar;
			}

		}
		return result;
	}
};

#endif // MATRIX_H
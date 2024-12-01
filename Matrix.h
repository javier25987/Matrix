#ifndef Matrix_H
#define Matrix_H

#include <vector>
#include <initializer_list>
#include <iostream>
#include <cmath>


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

// ================= javier's functions

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

	// ==========  here is javier's work

	int rang() const
	{
		int rows = _MX.size();
		int cols = _MX[0].size();

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
	
			std::cout << "vertical: " << v_ind << " ; horizontal: " << h_ind << std::endl;

			for (std::vector<double> x : matrix)
			{
				printV(x);
			}

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
					std::cout << "lv: " << i << " ; lh: " << j << " ; fac: " << factor << "\n";
					matrix[i][j] -= factor * matrix[v_ind][j];
				}
			}

			v_ind++;
			h_ind++;

			std::cout << "--------------------------------\n";
		}

		return rows;
	}
};

#endif // MATRIX_H

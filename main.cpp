#include <vector>
#include <initializer_list>
#include <iostream>
#include <vector>
#include "Matrix.h"

template <class T>
void printV(std::vector<T> vec)
{
    for (const T x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    Matrix<int> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    matrix.printM();

    printV(matrix.get_row(0));

    return 0;
}
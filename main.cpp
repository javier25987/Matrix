#include <vector>
#include <initializer_list>
#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
    Matrix<int> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    matrix.printM();

    printV(matrix.get_row(0));
    printV(matrix.get_colum(0));

    for (int i = 0; i < 4; i++)
    {
        matrix.transpose();
        matrix.printM();
    }
    return 0;
}
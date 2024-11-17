#include <vector>
#include <initializer_list>
#include <iostream>
#include <vector>
#include "Matrix.h"

// hello world, i'm enot and i'm not gay

int main() {
    Matrix<int> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    matrix.printM();

    printV(matrix.get_row(0));
    printV(matrix.get_colum(0));

    return 0;
}
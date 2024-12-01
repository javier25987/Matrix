#include <vector>
#include <initializer_list>
#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> matrix = 
    {
        {  1,  0, -1,  1 },
        {  2, -2,  1,  7 },
        { -1, -1,  3,  2 },
        {  0, -1,  1,  2 }
    };

    matrix.printM();

    printV(matrix.get_row(0));
    printV(matrix.get_colum(0));

    for (int i = 0; i < 4; i++)
    {
        matrix.transpose();
        matrix.printM();
    }

    std::cout << "Rang = " << matrix.rang() << "\n";

    system("pause");
    return 0;
}
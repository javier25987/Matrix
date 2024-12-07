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
    std::cout << "=======" << "\n";
    Matrix<int> E=
    {
        {  2,  0,  0,  0 },
        {  0,  1,  0,  0 },
        {  0,  0,  1,  0 },
        {  0,  0,  0,  1 }
    };
    std::cout << "Rang = " << E.rang() << "\n";

    (matrix * E).printM();
    std::cout << "=======" << "\n";
    (matrix + E).printM();
    std::cout << "=======" << "\n";
    (matrix - E).printM();
    std::cout << "=======" << "\n";
    (E + 1).printM();
    std::cout << "=======" << "\n";
    (E - 1).printM();
    std::cout << "=======" << "\n";
    (E * 1).printM();
    std::cout << "=======" << "\n";
    ((E * 8)/2).printM();

    system("pause");
    return 0;
}
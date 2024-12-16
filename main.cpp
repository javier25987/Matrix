#include <iostream>
#include "Matrix.h"
#include "fraction.h"

int main() {
    Matrix<fraction> fA =
    {
        {{1, 2}, {1, 3}, {5, 3}, {8, 7}},
        {{4, 8}, {7, 9}, {9, 4}, {5, 4}},
        {{1, 2}, {1, 3}, {5, 2}, {8, 5}},
        {{4, 8}, {7, 9}, {9, 4}, {5, 4}}
    };

    std::cout << "Matrix fA:\n";
    std::cout << fA << std::endl;

    Matrix<fraction> fB =
    {
        {{8, 3}, {7, 2}, {6, 5}, {5, 3}},
        {{8, 3}, {7, 2}, {6, 5}, {5, 3}},
        {{8, 3}, {7, 2}, {6, 5}, {5, 3}},
        {{8, 3}, {7, 2}, {6, 5}, {5, 3}}
    };

    std::cout << "Matrix fB:\n";
    std::cout << fB;

    std::cout << "---> fA + fB:\n";
    std::cout << fA + fB;
    std::cout << "---> fA - fB:\n";
    std::cout << fA - fB;
    std::cout << "---> fA * fB:\n";
    std::cout << fA * fB;
    std::cout << "---> fA * 3:\n";
    std::cout << fA * 3;

    Matrix<int> A =
    {
        { 1, 4, 2, 1 },
        {-1,-1, 3, 2 },
        { 0, 5, 7,-4 },
        { 2, 1,-3, 2 }
    };
    Matrix<int> B =
    {
        {  5,  9,  4,  5 },
        {  7,  1,  3,  9 },
        {  0,  4,  1,  2 },
        {  8,  5,  6,  7 }
    };
    Matrix<int> E =
    {
        {  1,  0,  0,  0 },
        {  0,  1,  0,  0 },
        {  0,  0,  1,  0 },
        {  0,  0,  0,  1 }
    };

    std::cout << "\nMatrix A:\n";
    std::cout << A;   
    std::cout << "\nMatrix B:\n";
    std::cout << B;
    std::cout << "\nMatrix E:\n";
    std::cout << E;

    std::cout << "\nRang A = " << A.rang() << "\n";
    std::cout << "Rang B = " << B.rang() << "\n";
    std::cout << "Rang E = " << E.rang() << "\n\n";

    std::cout << "See transpose B: \n";

    for (int i = 0; i < 2; i++)
    {
        B.transpose();
        std::cout << B;
    }

    std::cout << "Operations with Matrix:\n";
    std::cout << "--> A * B:\n";
    std::cout << A * B;
    std::cout << "--> A + B:\n";
    std::cout << A + B;
    std::cout << "--> A - B:\n";
    std::cout << A - B;
    std::cout << "--> A + const (5):\n";
    std::cout << A + 5;
    std::cout << "--> A - const (5):\n";
    std::cout << A - 5;
    std::cout << "--> E * const (8):\n";
    std::cout << E * 8;
    std::cout << "--> (E * 8) / 2:\n";
    std::cout << (E * 8) / 2;

    std::cout << "test super matrix:\n";

    Matrix<Matrix<int>> super_matrix = { {A}, {B} };

    std::cout << super_matrix;

    system("pause");
    return 0;
}

/*16_12_2024*/
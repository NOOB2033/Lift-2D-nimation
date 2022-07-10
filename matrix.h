#ifndef CG_LAB1_MATRIX_H
#define CG_LAB1_MATRIX_H


#include <iostream>
#include <vector>


class Matrix {

public:

    Matrix();

    Matrix& operator*=(const Matrix& other);
    Matrix operator*(const Matrix& other);
    std::vector<double>& getMatrix();

private:

    std::vector<double> matrix;

};


#endif //CG_LAB1_MATRIX_H
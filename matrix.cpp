#include "matrix.h"


Matrix::Matrix() {
    for (unsigned i = 0; i < 9; ++i) {
        matrix.push_back(0);
    }
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (matrix.size() != other.matrix.size()) {
        return *this;
    }

    Matrix new_matrix;
    for (unsigned i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            for (unsigned k = 0; k < 3; ++k) {
                new_matrix.getMatrix()[3 * i + j] += matrix[3 * i + k] * other.matrix[3 * k + j];
            }
        }
    }
    matrix = new_matrix.getMatrix();

    return *this;
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix copy = *this;
    return copy *= other;
}

std::vector<double>& Matrix::getMatrix() {
    return matrix;
}
#include "MatrixClass.h"

#include <stdexcept>

MatrixClass::MatrixClass(int rows, int cols)
    : rows_(rows), cols_(cols), values_(rows, std::vector<int>(cols, 0)) {
}

int MatrixClass::numRows() const {
    return rows_;
}

int MatrixClass::numCols() const {
    return cols_;
}

int MatrixClass::get(int row, int col) const {
    return values_.at(row).at(col);
}

void MatrixClass::set(int row, int col, int value) {
    values_.at(row).at(col) = value;
}

MatrixClass MatrixClass::add(const MatrixClass& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("Matrices must have the same dimensions.");
    }

    MatrixClass result(rows_, cols_);
    for (int row = 0; row < rows_; ++row) {
        for (int col = 0; col < cols_; ++col) {
            result.set(row, col, get(row, col) + other.get(row, col));
        }
    }
    return result;
}

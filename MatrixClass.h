#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H

#include <vector>

class MatrixClass {
public:
    MatrixClass(int rows, int cols);

    int numRows() const;
    int numCols() const;

    int get(int row, int col) const;
    void set(int row, int col, int value);

    MatrixClass add(const MatrixClass& other) const;

private:
    int rows_;
    int cols_;
    std::vector<std::vector<int>> values_;
};

#endif

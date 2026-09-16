#include "MatrixClass.h"

#include <iostream>

int main() {
    MatrixClass<int> a(2, 2);
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);

    MatrixClass<int> b(2, 2);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);

    MatrixClass<int> c = a.add(b);

    std::cout << "Integer matrix\n";
    std::cout << c.numRows() << " rows, " << c.numCols() << " cols\n";
    for (int row = 0; row < c.numRows(); ++row) {
        for (int col = 0; col < c.numCols(); ++col) {
            if (col > 0) {
                std::cout << ' ';
            }
            std::cout << c.get(row, col);
        }
        std::cout << '\n';
    }

    MatrixClass<double> x(2, 2);
    x.set(0, 0, 1.5);
    x.set(0, 1, 2.5);
    x.set(1, 0, 3.5);
    x.set(1, 1, 4.5);

    MatrixClass<double> y(2, 2);
    y.set(0, 0, 0.25);
    y.set(0, 1, 0.5);
    y.set(1, 0, 0.75);
    y.set(1, 1, 1.0);

    MatrixClass<double> z = x.add(y);

    std::cout << "\nDouble matrix\n";
    std::cout << z.numRows() << " rows, " << z.numCols() << " cols\n";
    for (int row = 0; row < z.numRows(); ++row) {
        for (int col = 0; col < z.numCols(); ++col) {
            if (col > 0) {
                std::cout << ' ';
            }
            std::cout << z.get(row, col);
        }
        std::cout << '\n';
    }

    return 0;
}

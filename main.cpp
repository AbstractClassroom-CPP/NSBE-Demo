#include "MatrixClass.h"

#include <iostream>

int main() {
    MatrixClass a(2, 2);
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);

    MatrixClass b(2, 2);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);

    MatrixClass c = a.add(b);

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

    return 0;
}

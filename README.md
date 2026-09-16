# NSBE-Demo

This is the repo created for Nathan Russell's NSBE demonstration on September 16, 2026.

A simple C++ matrix class in `MatrixClass.h` and `MatrixClass.cpp`, with an example in `main.cpp`.

```cpp
MatrixClass a(2, 3); // Rows, columns; all values start at zero.
MatrixClass b(2, 3);
a.set(0, 1, 4);     // Row and column indices start at zero.
b.set(0, 1, 2);
MatrixClass c = a.add(b);
int value = c.get(0, 1); // 6
// c.numRows() returns 2; c.numCols() returns 3.
```

Values are integers (`int`). Addition returns a new matrix and leaves both inputs unchanged.
Adding different dimensions throws `std::invalid_argument`; an invalid index throws `std::out_of_range`.

## Mac

Install the command-line tools if needed: `xcode-select --install`.
From the `NSBE-Demo` directory:

```bash
clang++ -std=c++11 -Wall -Wextra -pedantic MatrixClass.cpp main.cpp -o matrix_demo
./matrix_demo
```

## Windows (Git Bash)

Install a C++ compiler such as MinGW-w64 and put its `bin` directory on your Windows `PATH`.
Reopen Git Bash and check `g++ --version` works; Git Bash itself does not include a C++ compiler.
From the `NSBE-Demo` directory:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic MatrixClass.cpp main.cpp -o matrix_demo.exe
./matrix_demo.exe
```

Expected output on either platform:

```text
2 rows, 2 cols
6 8
10 12
```

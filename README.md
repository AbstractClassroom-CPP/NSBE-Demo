# NSBE-Demo

This is the repo created for Nathan Russell's NSBE demonstration on September 16, 2026.

A small C++ program that uses the matrix library from the separate
[MatrixClass repository](https://github.com/AbstractClassroom-CPP/MatrixClass).
Version `0.3.0` fetches MatrixClass version `3.0.0` and demonstrates
`MatrixClass<int>` and `MatrixClass<double>`.

| Demo version | MatrixClass dependency | C++ classes used |
| --- | --- | --- |
| [0.1.0](https://github.com/AbstractClassroom-CPP/NSBE-Demo/tree/0.1.0) | `1.0.0` | `MatrixClass` |
| [0.2.0](https://github.com/AbstractClassroom-CPP/NSBE-Demo/tree/0.2.0) | `2.0.0` | `IntegerMatrixClass`, `DoubleMatrixClass` |
| [0.3.0](https://github.com/AbstractClassroom-CPP/NSBE-Demo/tree/0.3.0) | `3.0.0` | `MatrixClass<int>`, `MatrixClass<double>` |

Each version is saved as a Git tag and pins its corresponding library tag.

```text
NSBE-Demo/
├── CMakeLists.txt
├── main.cpp
├── README.md
└── .gitignore
```

One class template now lives in the MatrixClass repository. Select the value type
in angle brackets; the methods work the same way:

```cpp
MatrixClass<int> a(2, 3); // Rows, columns; all values start at zero.
MatrixClass<int> b(2, 3);
a.set(0, 1, 4);     // Row and column indices start at zero.
b.set(0, 1, 2);
MatrixClass<int> c = a.add(b);
int value = c.get(0, 1); // 6
// c.numRows() returns 2; c.numCols() returns 3.

MatrixClass<double> x(2, 3);
MatrixClass<double> y(2, 3);
x.set(0, 1, 4.5);
y.set(0, 1, 1.25);
MatrixClass<double> z = x.add(y);
double approximateValue = z.get(0, 1); // 5.75
```

Include `MatrixClass.h` to use either supported type, `int` or `double`.
Addition takes another matrix with the same value type, returns a new matrix, and
leaves both inputs unchanged.
Adding different dimensions throws `std::invalid_argument`; an invalid index throws `std::out_of_range`.

## Build and run

You need Git, CMake 3.14 or newer, and a C++ compiler. The first configuration needs
internet access to fetch MatrixClass. You only need to clone NSBE-Demo; CMake handles
the dependency checkout inside `build/_deps/`.

```bash
git clone https://github.com/AbstractClassroom-CPP/NSBE-Demo.git
cd NSBE-Demo
```

If you already have this repository, run the following commands from its directory.

To get the original demo instead, clone tag `0.1.0` into a separate directory:

```bash
git clone --branch 0.1.0 https://github.com/AbstractClassroom-CPP/NSBE-Demo.git NSBE-Demo-0.1.0
cd NSBE-Demo-0.1.0
```

Use `--branch 0.2.0` or `--branch 0.3.0` with a matching directory name to clone
another tagged demo. The build commands below work for all three versions;
`0.1.0` prints only the integer result.

### Mac

Install CMake and Apple's command-line tools (`xcode-select --install`) if needed.

```bash
cmake -S . -B build -G "Unix Makefiles"
cmake --build build
./build/matrix_demo
```

### Windows (Git Bash)

Install CMake, Ninja, and a MinGW-w64 C++ compiler. Put their executable directories
on your Windows `PATH` and reopen Git Bash. Check that `cmake --version`,
`ninja --version`, `g++ --version`, and `git --version` work.

```bash
cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=g++
cmake --build build
./build/matrix_demo.exe
```

Expected output for version `0.3.0` on either platform (unchanged from `0.2.0`):

```text
Integer matrix
2 rows, 2 cols
6 8
10 12

Double matrix
2 rows, 2 cols
1.75 3
4.25 5.5
```

## How the dependency is connected

`FetchContent_Declare` records MatrixClass's Git URL and `GIT_TAG 3.0.0`.
`FetchContent_MakeAvailable` fetches it during configuration and adds its library target
to our build. `target_link_libraries` connects `matrix_demo` to
`MatrixClass::MatrixClass`, which supplies the include directory, library, and C++ requirement.

The `cmake -S . -B build` step configures and generates the build files. The
`cmake --build build` step invokes Make on Mac or Ninja with the Windows commands above.
After editing `main.cpp`, run `cmake --build build` again.
The dependency is pinned to version `3.0.0`, so changes to the library's `main` branch
do not change this demo release.

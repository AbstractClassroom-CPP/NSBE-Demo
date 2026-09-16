# NSBE-Demo

This is the repo created for Nathan Russell's NSBE demonstration on September 16, 2026.

A small C++ program that uses the integer matrix library from the separate
[MatrixClass repository](https://github.com/AbstractClassroom-CPP/MatrixClass).
CMake fetches that dependency from its `main` branch and builds it with the program.

```text
NSBE-Demo/
├── CMakeLists.txt
├── main.cpp
├── README.md
└── .gitignore
```

The class's header and implementation now live in the MatrixClass repository.
The code in `main.cpp` still uses the same interface:

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

## Build and run

You need Git, CMake 3.14 or newer, and a C++ compiler. The first configuration needs
internet access to fetch MatrixClass. You only need to clone NSBE-Demo; CMake handles
the dependency checkout inside `build/_deps/`.

```bash
git clone https://github.com/AbstractClassroom-CPP/NSBE-Demo.git
cd NSBE-Demo
```

If you already have this repository, run the following commands from its directory.

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

Expected output on either platform:

```text
2 rows, 2 cols
6 8
10 12
```

## How the dependency is connected

`FetchContent_Declare` records MatrixClass's Git URL and `GIT_TAG main`.
`FetchContent_MakeAvailable` fetches it during configuration and adds its library target
to our build. `target_link_libraries` connects `matrix_demo` to
`MatrixClass::MatrixClass`, which supplies the include directory, library, and C++ requirement.

The `cmake -S . -B build` step configures and generates the build files. The
`cmake --build build` step invokes Make on Mac or Ninja with the Windows commands above.
After editing `main.cpp`, run `cmake --build build` again.
To check for updates on the dependency's `main` branch, rerun the configuration command
and then build. Using a branch means the dependency can change between configurations.

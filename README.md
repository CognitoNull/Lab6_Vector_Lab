# Vector Calculator

This is my vector calculator for CPE 2600. It stores named vectors with x, y, and z values. You can add and subtract vectors, multiply a vector by a number, and save a result as another vector.

## Build

Use a Linux terminal with GCC and Make installed. From the project folder, run:

```bash
cd Week7
make
```

To remove the compiled files, run `make clean`.

## Run

From the `Week7` folder, run:

```bash
./minimat
```

Enter commands at the `minimat>` prompt. To show the help screen without starting the calculator, run:

```bash
./minimat -h
```

## Commands

- `help` shows the command list.
- `list` shows all stored vectors.
- `clear` removes all stored vectors and frees their memory.
- `quit` closes the calculator.
- `load test_vectors.csv` loads vectors from a CSV file. Matching names are replaced, and other stored vectors are kept.
- `save saved_vectors.csv` saves all stored vectors to a CSV file and overwrites the file if it already exists.
- `a = 1 2 3` creates a vector named `a`. Commas also work, like `a = 1,2,3`.
- `a` shows the values stored in vector `a`.
- `a + b` adds two vectors.
- `a - b` subtracts vector `b` from vector `a`.
- `a * 2` or `2 * a` multiplies a vector by a number.
- `c = a + b` stores the result in vector `c`. You can also store subtraction and multiplication results.

Create vectors before using them in a calculation. Using an existing name replaces that vector. A calculation without an assignment displays the result without storing it.

## CSV Files

Each line contains a vector name followed by its three values:

```csv
a,1,2,3
b,4,5,6
```

File paths can be relative or absolute, but cannot contain spaces. Include the full filename; the program does not add `.csv` for you. If loading stops because of a bad line, vectors loaded before that line stay in memory.

## Dynamic Memory

The program uses a dynamic array to store vectors. It starts with room for 10 vectors and doubles the space when the array fills up. The memory is freed when you enter `clear` or exit normally.

## Current Status

- `Week5` contains the earlier version of the calculator.
- `Week7` contains the version with dynamic memory.
- The Week 7 version also supports CSV loading and saving.
- `Labs` contains the lab handouts.

# Game of Life

This project is an implementation of Conway's Game of Life in C++ using threads to compute sub-regions of the grid.

## Files

- `main.cpp`: The main entry point of the program. It initializes the game, sets the initial state, and runs the simulation for a specified number of generations using multiple threads to compute sub-regions.
- `gol.cpp`: Contains the implementation of the `GameOfLife` class, which includes methods for setting the initial state, computing the next generation, and printing the grid.
- `Makefile`: A makefile to compile the project.

## How to Build

To build the project, you can use the provided Makefile. Simply run the following command in the terminal:

```
make
```
You can also use the following command to clean up the build files:

```
make clean
```

## How to Run

To run the program, you can use the following command:

```
./GOL <board_size> <root_threads> <max_generations>
```

Where:
- `<board_size>` is the size of the grid (must be a square).
- `<root_threads>` is the square root of the number of threads to use for the grid.
- `<max_generations>` is the number of generations to simulate.

## Note

it was assumed that the board_size % root_threads == 0

There are some initial states commented out in the main.cpp file that can be used to test the program. 
You will have to uncomment them and recompile the program to see the results.
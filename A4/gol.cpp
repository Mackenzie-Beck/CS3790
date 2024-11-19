#include <iostream>
#include <vector>

using namespace std;

// Class representing the Game of Life
class GameOfLife {
public:
    // Constructor to initialize the game with given rows and columns
    GameOfLife(int rows, int cols) : rows(rows), cols(cols) {
        grid.resize(rows, vector<int>(cols, 0)); // Initialize the grid with zeros
    }

    // Set the initial state of the grid
    void setInitialState(const vector<vector<int>>& initialState) {
        grid = initialState;
    }

    // Compute the next generation of the grid
    void nextGeneration() {
        vector<vector<int>> newGrid = grid; // Create a copy of the current grid

        // Iterate over each cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j); // Count live neighbors

                // Apply the rules of the Game of Life
                if (grid[i][j] == 1) { // If the cell is alive
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        newGrid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
                    }
                } else { // If the cell is dead
                    if (liveNeighbors == 3) {
                        newGrid[i][j] = 1; // Cell becomes alive due to reproduction
                    }
                }
            }
        }

        grid = newGrid; // Update the grid to the new generation
    }

    // Print the current state of the grid
    void printGrid() const {
        for (const auto& row : grid) {
            for (int cell : row) {
                cout << (cell ? 'O' : '.') << " "; // Print 'O' for alive and '.' for dead
            }
            cout << endl;
        }
    }

public:
    int rows, cols; // Dimensions of the grid
    vector<vector<int>> grid; // 2D grid representing the game state

    // Count the number of live neighbors for a given cell
    int countLiveNeighbors(int row, int col) const {
        int liveNeighbors = 0;
        // Check all neighboring cells
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue; // Skip the cell itself
                int newRow = row + i;
                int newCol = col + j;
                // Check if the neighbor is within bounds and alive
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    liveNeighbors += grid[newRow][newCol];
                }
            }
        }
        return liveNeighbors;
    }
};


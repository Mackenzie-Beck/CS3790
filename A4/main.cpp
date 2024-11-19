#include "gol.cpp"
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <board_size> <root_threads> <max_generations>" << std::endl;
        return 1;
    }

    // Convert command-line arguments to integers
    int board_size = std::stoi(argv[1]);
    int root_threads = std::stoi(argv[2]);
    int max_generations = std::stoi(argv[3]);

    // Create an instance of the GameOfLife class
    GameOfLife game(board_size, board_size);

    // srand(time(0)); // Seed the random number generator with the current time
    // vector<vector<int>> initialState(board_size, vector<int>(board_size, 0));

    // for (int i = 0; i < board_size; ++i) {
    //     for (int j = 0; j < board_size; ++j) {
    //         initialState[i][j] = rand() % 2; // Randomly set each cell to 0 or 1
    //     }
    // }

    // // Set the initial state of the grid
    // game.setInitialState(initialState);

    // Create an initial state that is a glider
    vector<vector<int>> initialState(board_size, vector<int>(board_size, 0));

    // Initialize a glider in the top left
    if (board_size >= 3) {
        initialState[0][1] = 1;
        initialState[1][2] = 1;
        initialState[2][0] = 1;
        initialState[2][1] = 1;
        initialState[2][2] = 1;
    }




    // Set the initial state of the grid
    game.setInitialState(initialState);

    // Print the initial state of the grid
    cout << "Initial State:" << endl;
    game.printGrid();


    // Create row and column sections
    int num_row_sections = board_size / root_threads;
    int num_col_sections = board_size / root_threads;

    // Function to compute the next generation for a sub-region
    auto computeSubRegion = [&](int start_row, int end_row, int start_col, int end_col, vector<vector<int>>& nextGrid) {
        for (int i = start_row; i <= end_row; ++i) {
            for (int j = start_col; j <= end_col; ++j) {
                int liveNeighbors = game.countLiveNeighbors(i, j); // Count live neighbors

                // Apply the rules of the Game of Life
                if (game.grid[i][j] == 1) { // If the cell is alive
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        nextGrid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
                    } else {
                        nextGrid[i][j] = 1; // Cell stays alive
                    }
                } else { // If the cell is dead
                    if (liveNeighbors == 3) {
                        nextGrid[i][j] = 1; // Cell becomes alive due to reproduction
                    } else {
                        nextGrid[i][j] = 0; // Cell stays dead
                    }
                }
            }
        }
    };

    // For MAX number of generations
    for (int gen = 0; gen < max_generations; ++gen) {
        vector<thread> threads;
        vector<vector<int>> nextGrid(board_size, vector<int>(board_size, 0)); // Create a separate grid for the next state
        int total_threads = root_threads * root_threads;

        // Create threads and assign them their respective row/column regions
        for (int t = 0; t < total_threads; ++t) {
            int start_row = (t / root_threads) * num_row_sections;
            int end_row = min(start_row + num_row_sections, board_size) - 1;
            int start_col = (t % root_threads) * num_col_sections;
            int end_col = min(start_col + num_col_sections, board_size) - 1;

            threads.emplace_back(computeSubRegion, start_row, end_row, start_col, end_col, ref(nextGrid));
        }

        // Wait for all threads to finish
        for (auto& th : threads) {
            th.join();
        }

        // Update the main grid with the computed next state
        game.grid = nextGrid;

        // Draw the generation
        cout << "Generation " << gen + 1 << ":" << endl;
        game.printGrid();
    }


    




    return 0;
}

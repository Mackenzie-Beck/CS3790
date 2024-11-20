#include "gol.cpp"
#include <thread>
#include <functional> // Include for std::bind

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


    // Create an initial state 
    vector<vector<int>> initialState(board_size, vector<int>(board_size, 0));



    // Uncomment one of the following initial states to use it, some will not work if the board_size is too small

    // Glider
    // if (board_size >= 3) {
    //     initialState[0][1] = 1;
    //     initialState[1][2] = 1;
    //     initialState[2][0] = 1;
    //     initialState[2][1] = 1;
    //     initialState[2][2] = 1;
    // }

    //Small Exploder
    // if (board_size >= 3) {
    //     initialState[6][5] = 1;
    //     initialState[6][6] = 1;
    //     initialState[6][7] = 1;
    //     initialState[5][6] = 1;
    //     initialState[7][6] = 1;
    // }

    // Exploder
    // if (board_size >= 5) {
    //     initialState[5][5] = 1;
    //     initialState[5][7] = 1;
    //     initialState[5][9] = 1;
    //     initialState[6][5] = 1;
    //     initialState[6][9] = 1;
    //     initialState[7][5] = 1;
    //     initialState[7][9] = 1;
    //     initialState[8][5] = 1;
    //     initialState[8][9] = 1;
    //     initialState[9][5] = 1;
    //     initialState[9][7] = 1;
    //     initialState[9][9] = 1;
    // }

    // 10 Cell Row
    // if (board_size >= 10) {
    //     for (int i = 0; i < 10; ++i) {
    //         initialState[board_size / 2][i] = 1;
    //     }
    // }

    // Lightweight Spaceship
if (board_size >= 5) {
    initialState[6][0] = 1;
    initialState[6][3] = 1;
    initialState[7][4] = 1;
    initialState[8][0] = 1;
    initialState[8][4] = 1;
    initialState[9][1] = 1;
    initialState[9][2] = 1;
    initialState[9][3] = 1;
    initialState[9][4] = 1;
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
    // originally had this as a lambda but decided to move it to the gol class
    // auto computeSubRegion = [&](int start_row, int end_row, int start_col, int end_col, vector<vector<int>>& nextGrid) {
    //     for (int i = start_row; i <= end_row; ++i) {
    //         for (int j = start_col; j <= end_col; ++j) {
    //             int liveNeighbors = game.countLiveNeighbors(i, j); // Count living neighbors

    //             // Apply the rules of the Game of Life
    //             if (game.grid[i][j] == 1) { // If the cell is alive
    //                 if (liveNeighbors < 2 || liveNeighbors > 3) {
    //                     nextGrid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
    //                 } else {
    //                     nextGrid[i][j] = 1; // Cell stays alive
    //                 }
    //             } else { // If the cell is dead
    //                 if (liveNeighbors == 3) {
    //                     nextGrid[i][j] = 1; // Cell becomes alive due to reproduction
    //                 } else {
    //                     nextGrid[i][j] = 0; // Cell stays dead
    //                 }
    //             }
    //         }
    //     }
    // };

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

            threads.emplace_back(bind(&GameOfLife::computeSubRegion, &game, start_row, end_row, start_col, end_col, ref(nextGrid))); // Use std::bind to pass the member function
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

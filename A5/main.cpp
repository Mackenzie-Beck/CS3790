#include "bankersAlg.hpp"
#include "common.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input file>" << endl;
        return 1;
    }

    cout << "Banker's Algorithm" << endl;

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int N, M;
    inputFile >> N >> M;

    matrix MAX(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            inputFile >> MAX[i][j];
        }
    }

    vector<int> AVAILABLE(M);
    for (int j = 0; j < M; ++j) {
        inputFile >> AVAILABLE[j];
    }

    inputFile.close();

    // shape need, alloc, available vector
    vector<vector<int>> ALLOCATION(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ALLOCATION[i][j] = 0;
        }
    }

    vector<vector<int>> NEED(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
        }
    }

    // prompt user for request
    int processID;
    vector<int> request(M);
    while (true) {
        cout << "MAX matrix:" << endl;
        for (const auto& row : MAX) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "ALLOCATION matrix:" << endl;
        for (const auto& row : ALLOCATION) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "AVAILABLE vector:" << endl;
        for (const auto& elem : AVAILABLE) {
            cout << elem << " ";
        }
        cout << endl;

        cout << "NEED matrix:" << endl;
        for (const auto& row : NEED) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << "Enter process ID (or -1 to exit): ";
        while (!(cin >> processID)) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter an integer for process ID: ";
        }
        if (processID == -1) {
            break;
        }



        for (int j = 0; j < M; ++j) {
            cout << "Enter request for resource " << j << ": ";
            while (!(cin >> request[j])) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input. Please enter an integer for resource " << j << ": ";
            }
        }
        // call bankersAlgorithm
        cout << "Calling bankersAlgorithm" << endl;
        bankersAlgorithm(AVAILABLE, request, MAX, ALLOCATION, NEED, processID);
    }

    return 0;
}
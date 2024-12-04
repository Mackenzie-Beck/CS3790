/*
    Banker's Algorithm
    Implementation of the Banker's Algorithm in C++
*/

#include "bankersAlg.hpp"
#include "common.hpp"

using namespace std;

void bankersAlgorithm(
    vector<int>& AVAILABLE,
    const vector<int>& REQUEST,
    const matrix& MAX,
    matrix& ALLOCATION,
    matrix& NEED,
    int processID
) {
    cout << "Enter bankersAlgorithm" << endl;

    // check if request is less than or equal to NEED[processID]
    if (REQUEST <= NEED[processID]) {
        cout << "REQUEST <= NEED" << endl;
        
        // Check if REQUEST <= AVAILABLE
        if (REQUEST <= AVAILABLE) {
            // check if the request can be granted
            cout << "REQUEST <= AVAILABLE" << endl;
            
            // Temporarily allocate resources
            vector<int> tmpAVAILABLE = AVAILABLE;
            for (size_t i = 0; i < tmpAVAILABLE.size(); ++i) {
                tmpAVAILABLE[i] -= REQUEST[i];
            }
            matrix tmpALLOCATION = ALLOCATION;
            for (size_t i = 0; i < tmpALLOCATION[processID].size(); ++i) {
                tmpALLOCATION[processID][i] += REQUEST[i];
            }

            matrix tmpNEED = NEED;
            for (size_t i = 0; i < tmpNEED[processID].size(); ++i) {
                tmpNEED[processID][i] -= REQUEST[i];
            }
            // Check system safety

            if (safetyAlgorithm(tmpAVAILABLE, tmpNEED, tmpALLOCATION)) {
                cout << "The request can be granted." << endl;
                
                // Update AVAILABLE
                AVAILABLE = tmpAVAILABLE;
                
                // Update ALLOCATION and NEED matrices
                for (size_t i = 0; i < ALLOCATION[processID].size(); ++i) {
                    ALLOCATION[processID][i] += REQUEST[i];
                    NEED[processID][i] -= REQUEST[i];
                }
            } else {
                cerr << "Error: The system does not have enough resources to satisfy the request without causing a deadlock." << endl;
            }
        } else {
            // Request exceeds available resources
            cerr << "Request exceeds available resources." << endl;
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

            cout << "NEED matrix:" << endl;
            for (const auto& row : NEED) {
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

            cerr << "Error: The request exceeds the available resources." << endl;
            return;
        }
    } else {
        // Request exceeds the process's needs
        cerr << "Error: The request exceeds the process's needs." << endl;
    }
}

bool safetyAlgorithm(
    vector<int> WORK,
    const matrix NEED,
    const matrix ALLOCATION
) {
    // Initialize finish vector, all false
    vector<bool> finish(ALLOCATION.size(), false);
    matrix tmpNEED = NEED;
    matrix tmpALLOCATION = ALLOCATION;

    for (size_t i = 0; i < tmpNEED.size(); i++) {
        if (tmpNEED[i] <= WORK && finish[i] == false) {
            WORK = WORK + tmpALLOCATION[i];
            finish[i] = true;
        }
    }

    return finish == vector<bool>(finish.size(), true);
}

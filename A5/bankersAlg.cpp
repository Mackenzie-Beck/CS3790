/*
    Banker's Algorithm
    Implentation of the Banker's Algorithm in C++
*/

#include "common.hpp"

using namespace std;


// Overload <= operator for vectors
template<typename T>
bool operator<=(const vector<T>& a, const vector<T>& b) {
    if (a.size() != b.size()) return false;
    
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) return false;
    }
    return true;
}

//overload + operator for vectors
template<typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b) {
    vector<T> result = a;
    for (size_t i = 0; i < a.size(); i++) {
        result[i] += b[i];
    }
    return result;
}


void bankersAlgorithm(int N, int M, matrix MAX, vector<int> AVAILABLE) {
    // Function implementation here
}


bool safetyAlgorithm(vector<int> work, matrix need, matrix allocation) {
    // Function implementation here
    // Initialize finish matrix, all false
    vector<bool> finish(allocation.size(), false);

    // Find an i such that both finish[i] == false and need[i] <= work
    for (int i = 0; i < allocation.size(); i++) {
        if (finish[i] == false && need[i] <= work) {
            finish[i] = true;
            vector<int> tmpRow = allocation[i];
            work = work + tmpRow;
        }
    }

    // If finish == [true, true, ... true], return true
    if (finish == vector<bool>(finish.size(), true)) {
        return true;
    }
    return false;
}

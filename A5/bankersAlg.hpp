// Keep only declarations in the header
#ifndef BANKERSALG_HPP
#define BANKERSALG_HPP

#include "common.hpp"

// Operator overloads defined as inline to prevent multiple definitions
template<typename T>
inline bool operator<(const vector<T>& a, const vector<T>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {  // All elements of 'a' must be strictly less than 'b'
            return false;
        }
    }
    return true;
}

template<typename T>
inline bool operator<=(const vector<T>& a, const vector<T>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) {   // All elements of 'a' must be less than or equal to 'b'
            return false;
        }
    }
    return true;
}

template<typename T>
inline vector<T> operator+(const vector<T>& a, const vector<T>& b) {
    vector<T> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

// Function declarations with references for modification
void bankersAlgorithm(
    vector<int>& AVAILABLE,
    const vector<int>& REQUEST,
    const matrix& MAX,
    matrix& ALLOCATION,
    matrix& NEED,
    int processID
);

bool safetyAlgorithm(
    vector<int> WORK,
    const matrix NEED,
    const matrix ALLOCATION
);

#endif // BANKERSALG_HPP
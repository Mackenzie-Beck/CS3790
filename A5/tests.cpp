#include "bankersAlg.cpp"
#include <cassert>

void testSafetyAlgorithm() {
    // Test case 1
    vector<int> work1 = {3, 3, 2};
    matrix need1 = {{1, 0, 0}, {2, 1, 1}, {3, 3, 2}};
    matrix allocation1 = {{2, 0, 0}, {1, 1, 1}, {1, 2, 2}};
    assert(safetyAlgorithm(work1, need1, allocation1) == true);

    // Test case 2
    vector<int> work2 = {1, 1, 1};
    matrix need2 = {{1, 0, 0}, {2, 1, 1}, {3, 3, 2}};
    matrix allocation2 = {{2, 0, 0}, {1, 1, 1}, {1, 2, 2}};
    assert(safetyAlgorithm(work2, need2, allocation2) == false);

    // Test case 3
    vector<int> work3 = {10, 5, 7};
    matrix need3 = {{0, 0, 0}, {1, 0, 2}, {1, 3, 5}};
    matrix allocation3 = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}};
    assert(safetyAlgorithm(work3, need3, allocation3) == true);

    // Test case 4
    vector<int> work4 = {0, 0, 0};
    matrix need4 = {{1, 0, 0}, {2, 1, 1}, {3, 3, 2}};
    matrix allocation4 = {{2, 0, 0}, {1, 1, 1}, {1, 2, 2}};
    assert(safetyAlgorithm(work4, need4, allocation4) == false);

    cout << "All test cases passed!" << endl;
}

int main() {
    testSafetyAlgorithm();
    return 0;
}

#include <vector>
#include <unordered_set>
#include <cstdint>
#include <iostream>

using namespace std;

void zero_cross(vector<vector<int>> &a) {
    if (a.empty() || a[0].empty()) {
        cout << "u trippin cuh" << std::endl;
        return;
    }
    unordered_set<int> r, c;

    for (uint8_t i = 0; i < a.size(); i++) {
        for (uint8_t j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 0) {
                r.insert(i);
                c.insert(j);
            }
        }
    }

    for (uint8_t i = 0; i < a.size(); i++) {
        if (r.find(i) != r.end()) {
            for (uint8_t j = 0; j < a[0].size(); j++) {
                a[i][j] = 0;
            }
        }
    }
    for (uint8_t j = 0; j < a[0].size(); j++) {
        if (r.find(j) != r.end()) {
            for (uint8_t i = 0; i < a.size(); i++) {
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> a = {{1, 2, 3, 3}, {4, 0, 6, 3}, {7, 8, 9, 3}};
    for (vector<int> &r : a) {
        for (int val : r) {
            cout << val << " ";

        } cout << std::endl;
    } cout << std::endl;

    zero_cross(a);

    for (vector<int> &r : a) {
        for (int val : r) {
            cout << val << " ";

        } cout << std::endl;
    } cout << std::endl;


    return 0;
}
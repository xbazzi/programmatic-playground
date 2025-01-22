#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate_right(const vector<vector<int>> &a) {
    if (a.empty() || a[0].empty()) return {};

    int N = a.size();
    int M = a[0].size();

    vector<vector<int>> rotated(a.size(), vector<int>(a.size()));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            rotated[j][M - i - 1] = a[i][j];
        }
    }
    return std::move(rotated);
}

vector<vector<int>> rotate_right(const vector<vector<int>> &a) {
    if (a.empty() || a[0].empty()) return {};

    int N = a.size();
    int M = a[0].size();

    vector<vector<int>> rotated(a.size(), vector<int>(a.size()));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            rotated[j][M - i - 1] = a[i][j];
        }
    }
    return std::move(rotated);
}

void rotate_right_inplace(vector<vector<int>> &a) {
    if (a.empty() || a[0].empty()) return;

    int N = a.size();
    int M = a[0].size();

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            // Swap values once
            a[i][j] ^= a[j][M - i - 1];
            a[j][M - i - 1] ^= a[i][j];
            a[i][j] ^= a[j][M - i - 1];

            // Swap again to fix misses
            
            a[i][j] ^= a[N - i - 1][M - j - 1];
            a[N - i - 1][M - j - 1] ^= a[i][j];
            a[i][j] ^= a[N - i - 1][M - j - 1];

        }
    }
}

int main() {
    vector<vector<int>> a = {{1, 2, 3, 3}, {4, 5, 6, 3}, {7, 8, 9, 3}, {7, 8, 9, 3}};
    vector<vector<int>> result = rotate_right(a);
    // rotate_right_inplace(a);

    // print `a`
    for (vector<int> &v : a) {
        for (int k : v) {
            cout << k << " ";

        }
        cout << std::endl;
    }

    cout << std::endl;
    // print `result`
    for (vector<int> &v : result) {
        for (int k : v) {
            cout << k << " ";

        }
        cout << std::endl;
    } cout << std::endl;


    return 0;
}
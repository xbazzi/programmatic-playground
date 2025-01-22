#include <string>
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;
using namespace std::literals;

int find(const string &s, const string &f) {
    uint32_t hpattern{static_cast<uint32_t>(0)}, htext{static_cast<uint32_t>(0)};
    uint32_t N = f.size();
    uint32_t p = UINT32_MAX;
    
    for (uint32_t i = 0; i < N; i++) {
        cout << "the numbers mason: ";
        cout << (1 << N - i - 1) << std::endl;
        hpattern = (hpattern + f[i] * (1 << (N - i - 1))) % p;
        htext = (htext + s[i] * (1 << (N - i - 1))) % p;
    }

    bool found = false;
    for (uint32_t i = 0; i <= s.size() - N; i++) {
        // check for match
        cout << hpattern << ", " << htext << std::endl;
        if (hpattern == htext) {
            //  Rule out collisions
            for (uint32_t j = 0; j < N; j++) {
                cout << j << ", " << s[i + j] << ", " << f[j] << std::endl;
                if (s[i + j] != f[j]) {
                    cout << "breaking" << std::endl;
                    found = false;
                    break;
                }
                found = true;
            }
        }
        if (found) return i;
        htext = (htext - s[i] * (1 << (N - 1))) * 2 + s[i + N];
    }
    return -1;
}

int main() {
    string s = "hello world";
    const string &f = "lo ";
    const int p = find(s, f);
    if (p < 0) {
        cout << "not found :/" << std::endl;
        return 0;
    }
    cout << "Found it at position " << p << ", which is " << s[p] << std::endl;

    return 0;
}
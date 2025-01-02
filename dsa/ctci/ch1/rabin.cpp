#include <string>
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

int find(const string &s, const string &f) {
    if (f.empty() || s.size() < f.size()) return -1;

    uint32_t hpattern{0}, htext{0};
    uint32_t N = f.size();
    uint32_t p = 101;
    uint32_t power = 1;

    // Compute initial powers of 2 modulo p
    for (uint32_t i = 0; i < N - 1; i++) {
        power = (power * 2) % p;
    }

    // Calculate hash values for pattern and first window
    for (uint32_t i = 0; i < N; i++) {
        hpattern = (hpattern * 2 + f[i]) % p;
        htext = (htext * 2 + s[i]) % p;
    }

    // Slide over the string
    for (uint32_t i = 0; i <= s.size() - N; i++) {
        if (hpattern == htext) {
            // Verify character by character
            bool match = true;
            for (uint32_t j = 0; j < N; j++) {
                if (s[i + j] != f[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }

        // Update hash for next window
        if (i < s.size() - N) {
            htext = (htext - s[i] * power + p) % p; // Remove leading character
            htext = (htext * 2 + s[i + N]) % p;    // Add trailing character
        }
    }
    return -1;
}

int main() {
    string s = "hello world!";
    const string &f = "world";
    int p = find(s, f);
    if (p < 0) {
        cout << "not found :/" << endl;
    } else {
        cout << "Found it at position " << p << ": " << s.substr(p, f.size()) << endl;
    }
    return 0;
}

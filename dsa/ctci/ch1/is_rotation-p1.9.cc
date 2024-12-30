#include <string>
#include <cstdint>
#include <iostream>

using namespace std;
using namespace std::literals;

bool is_rotation(string s1, string s2) {
    uint8_t j{0}, i{0}, count{0}, lim{0};

    if (s1.size() != s2.size()) return 0;
    uint8_t len = s1.size();

    while (i < len) {
        if (lim > len * 2) break;
        if (s1[i] != s2[j]) {
            j = (j + 1) % len;
            ++lim;
        } else {
            count++; i++; j = (j + 1) % len;
        }
    }
    return count == len;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "usage: 'is_rotation s1 s2'" << std::endl;
    }
    cout << boolalpha << is_rotation(argv[1], argv[2]);

    return 0;
}
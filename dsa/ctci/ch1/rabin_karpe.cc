#include <string>
#include <iostream>
#include <cstdint>

using namespace std;
using namespace std::literals;

const char* find(const string &s, const string &f) {
    uint32_t match{static_cast<uint32_t>(f[0])}, hash{static_cast<uint32_t>(s[0])}, count{0};
    uint32_t N = f.size();
    

    for (uint32_t i = 1; i < N; i++) {
        match += f[i];
        hash += s[i];
    }

    for (uint32_t i = N; i < s.size(); i++) {
        hash += s[i] - s[i - N];
        if (match == hash) {
            count = 0;
            //  Rule out collisions
            for (uint32_t j = 0; j < N; j++) {
                if (f[j] == s[i + j + 1 - N]) {
                    count++;
                }
            }
            if (count == N) return &(s[i - N + 1]);
        }
    }
    return nullptr;
}

int main() {
    string s = "hello world!";
    const string &f = "world";
    const char* p = find(s, f);
    if (p) {
        cout << "position: " << p - s.c_str();
        return 0;
    }
    cout << "not found :(";
    return 0;
}
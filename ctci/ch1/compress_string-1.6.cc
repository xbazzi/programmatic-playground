#include <string>
#include <iostream>
#include <sstream>

using namespace std;

auto compress_string(string &s) -> string {
    size_t freq = 1;
    ostringstream result;//new string();

    for (size_t i = 0; i < s.size(); i++) {
        if (i + 1 == s.size() || s[i] != s[i+1]) {
            result << s[i] << freq;
            freq = 1;
        } else {
            freq++;
        }
    }
    return (result.str()).size() <= s.size() ? result.str() : s;
}

int main() {
    string s = "hhhoooooola";
    string result = compress_string(s);
    cout << result << std::endl;
}
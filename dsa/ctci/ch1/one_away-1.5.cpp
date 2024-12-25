#include <string>
#include <iostream>

using namespace std;

bool is_one_away(string s1, string s2) {
    size_t s1_sz = s1.size();
    size_t s2_sz = s2.size();
    // cout << "s1sz: " << s1_sz << ", s2_sz: " << s2_sz << std::endl;
    // cout << "diff s1 - s2: " << s1_sz - s2_sz << std::endl;
    // cout << "type of size()" << typeid(s1.size()).name() << std::endl;
    if (abs(static_cast<int>(s1_sz) - static_cast<int>(s2_sz)) > 1) return 0;
    // if (abs((s1_sz) - (s2_sz)) > 1) return 0;
    size_t i = 0, j = 0, diff = 0;

    while (j < s2_sz && i < s1_sz) {
        cout << i << " " << j << ", " << s1[i] << " " << s2[j] << std::endl;
        bool expr = s1[i] != s2[i];
        if (s1[i] != s2[j]) {
            if (s1_sz > s2_sz) {
                cout << "s1 > s2" << std::endl;
                i++; diff++; continue;
            } else if (s1_sz < s2_sz) {
                cout << "s1 < s2" << std::endl;
                j++; diff++; continue;
            } else {
                i++; j++; diff++; continue;
            }
        }
        // cout << "diff: " << diff << " ";
        i++; j++;
        // if ( i > )
    }
    return diff < 2;
}

int main() {
    string s1 = "hello";
    string s2 = "elloh";
    bool result = is_one_away(s1, s2);
    cout << "is_one_away: " << boolalpha << result << std::endl;
}
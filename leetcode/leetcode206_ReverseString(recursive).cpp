class Solution {
public:
    int temp = 0;
    void reverseString(vector<char>& s) {
        reverseHelper(0, s.size() - 1, s);
    }
    void reverseHelper(int i, int j, vector<char>& vec) {
        if (i >= j) return;
        std::swap(vec[i], vec[j]);
        reverseHelper(i + 1, j - 1, vec);
    }
};
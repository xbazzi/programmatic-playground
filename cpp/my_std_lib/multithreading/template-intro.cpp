#include <iostream>

template<typename T>
T&& max(T&& a, T&& b) {
    return a > b ? a : b;
}

int main() {
    int a = 0, b = 2;
    std::cout << max<int>(std::move(a), std::move(b)) << std::endl;
    return 0;
}
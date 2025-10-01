#include <iostream>
#include <cstdint>
#include <cstddef>

void print(char const *str) { std::cout << 'a'; }
void print(short num) { std::cout << 'b'; }

int main() {
  print((short)0);
}
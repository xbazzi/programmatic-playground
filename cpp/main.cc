#include "RedBlackTree.cc"
#include <cstdint>
#include <iostream>

using namespace rbtree;

int main()
{
    RedBlackTree<uint8_t> tree{};

    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    tree.insert(6);
    tree.insert(18);
    tree.insert(14);
    tree.insert(19);
    tree.insert(12);
    tree.insert(5);
    tree.insert(3);

    tree.print();
    return 0;
}
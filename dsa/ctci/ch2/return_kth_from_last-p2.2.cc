#include <iostream>
#include "ListNode.hh"
#include <cstddef>

ListNode* return_kth_from_last(ListNode *head, size_t k) {
    size_t count = 0;
    ListNode *node = head;
    while(node->next) {
        ++count;
        node = node->next.get();
    }
    node = head;
    for (size_t i = 0; i < count - k; i++) {
        node = node->next.get();
    }
    return node;

}
int main () {
    auto node1 = std::make_unique<ListNode>(1);
    auto node2 = std::make_unique<ListNode>(2);
    auto node3 = std::make_unique<ListNode>(3);
    auto node4 = std::make_unique<ListNode>(4);
    node1->next = std::move(node2);
    node1->next->next = std::move(node3);
    node1->next->next->next = std::move(node4);
    node1->print_list();
    std::cout << return_kth_from_last(node1.get(), 0)->value << std::endl;
    return 0;
}
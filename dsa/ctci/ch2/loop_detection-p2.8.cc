#include <iostream>
#include "ListNode.hh"
#include <unordered_set>
#include <atomic>

using namespace std;
using IntNode = Node<int>;

IntNode* get_loop(IntNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }

    IntNode* current = head;
    unordered_set<IntNode*> seen;
    while (current) {
        if (seen.count(current)) {
            return current;
        }
        seen.insert(current);
        current = current->next;
    }
    return nullptr;
}

IntNode* get_loop_inplace(IntNode* head) {

    IntNode* slow = head;
    IntNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (!fast || !fast->next) {
        return nullptr;
    }

    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}


bool has_loop(IntNode* head) {
    if (!head || !head->next) {
        return 0;
    }

    IntNode* slow = head;
    IntNode* fast = head->next;
    while (slow && fast) {
        if (slow == fast) {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main() {
    IntNode *node1 = new IntNode(1);
    IntNode *node2 = new IntNode(2);
    IntNode *node3 = new IntNode(3);
    IntNode *node4 = new IntNode(4);

    node1->next = node2;
    node1->next->next = node3;
    node1->next->next->next = node4;
    node1->next->next->next = node3;

    if (has_loop(node1)) {
        IntNode *culprit = get_loop_inplace(node1);
        std::cout << "The loop starts at " << culprit->value << ", address = " << &culprit << std::endl;
    }

    node1->print_list();
    return 0;
}

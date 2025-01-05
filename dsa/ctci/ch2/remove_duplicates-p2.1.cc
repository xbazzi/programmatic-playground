#include <iostream>
#include <memory>
#include <unordered_set>

using namespace std;

class ListNode {
public:
    ListNode() : value{0}, next{nullptr}
    {}

    ListNode(int val) : value{val}, next{nullptr}
    {}

    int value;
    unique_ptr<ListNode> next;

    void remove_duplicates() {
        ListNode *current = this;
        unordered_set<int> seen;
        seen.insert(current->value);

        while (current && current->next) {
            if (seen.count(current->next->value)) {
                cout << "found one of em: " << current->next->value;
                current->next = std::move(current->next->next);
            } else {
                seen.insert(current->next->value);
                current = current->next.get();
            }
        }
        cout << endl;
        return;
    }

    void print_list() const {
        ListNode const *current = this;
        while(current) {
            cout << current->value << " ";
            current = current->next.get();
        } cout << endl;
    }
};

int main() {
    unique_ptr<ListNode> node1 = make_unique<ListNode>(3);
    unique_ptr<ListNode> node2 = make_unique<ListNode>(3);
    unique_ptr<ListNode> node3 = make_unique<ListNode>(3);
    unique_ptr<ListNode> node4 = make_unique<ListNode>(3);
    node1->next = std::move(node2);
    node1->next->next = std::move(node3);
    node1->next->next->next = std::move(node4);

    node1->print_list();
    node1->remove_duplicates();
    node1->print_list();

    // unique_ptr<ListNode> head = std::move(node1);

    // cout << node->value << ", " << node->next->value << std::endl;
    return 0;
}
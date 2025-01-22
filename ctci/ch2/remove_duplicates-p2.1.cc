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
                current->next = std::move(current->next->next);
            } else {
                seen.insert(current->next->value);
                current = current->next.get();
            }
        }
        cout << endl;
        return;
    }

    void remove_duplicates_inplace() {
        if (!this || !this->next) return;

        ListNode *current = this;

        while (current) {
            ListNode* prev = current;
            ListNode* runner = prev->next.get();

            while(runner) {
                if (current->value == runner->value) {
                    prev->next = move(runner->next);
                    runner = prev->next.get();

                } else {
                    prev = runner;
                    runner = runner->next.get();
                }
            }
            current = current->next.get();
        }
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
    unique_ptr<ListNode> node1 = make_unique<ListNode>(4);
    unique_ptr<ListNode> node2 = make_unique<ListNode>(3);
    unique_ptr<ListNode> node3 = make_unique<ListNode>(5);
    unique_ptr<ListNode> node4 = make_unique<ListNode>(3);
    node1->next = std::move(node2);
    node1->next->next = std::move(node3);
    node1->next->next->next = std::move(node4);

    node1->print_list();
    cout << "removing dupes..." << endl;
    node1->remove_duplicates_inplace();
    node1->print_list();

    // unique_ptr<ListNode> head = std::move(node1);

    // cout << node->value << ", " << node->next->value << std::endl;
    return 0;
}
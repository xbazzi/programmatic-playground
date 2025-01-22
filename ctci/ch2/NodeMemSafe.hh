#include <memory>

class ListNode {
public:
    ListNode() : value{0}, next{nullptr}
    {}

    ListNode(int val) : value{val}, next{nullptr}
    {}

    int value;
    std::unique_ptr<ListNode> next;

    void print_list() const {
        ListNode const *current = this;
        while(current) {
            std::cout << current->value << " ";
            current = current->next.get();
        } std::cout << std::endl;
    }
};
#include <type_traits>
#include <sstream>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
class Node {
public:
    Node() : value{0}, next{nullptr}
    {}

    Node(T val) : value{val}, next{nullptr}
    {}

    Node *next;
    T value;

    void print_list() {
        Node* current = this;
        std::ostringstream ss;
        ss << "List: ";
        size_t count = 0, max_count = 50;
        while (current) {
            ss << current->value << " ";
            current = current->next;
            count++;
            if (count > max_count) {
                ss << std::endl << "Max size (50) exceeded or there is a loop.";
                break;
            }
        } ss << std::endl;

        std::cout << ss.str();
    }
};
#include <concepts>
#include <stdexcept>


template <class T>
class Stack {
public:
    class StackNode {
    public:
        StackNode() : data{0}, next{nullptr}
        {}

        StackNode(const T& some_data) : data{some_data}, next{nullptr}
        {}

    // why not private?
    private:
        T data;
        StackNode *next{nullptr};
    };

    void push(const T& new_data) {
        StackNode* new_node{new StackNode(new_data)};
        new_node->next{top_node};
        top_node{new_node};
        return;
    }

    T top() {
        if (!top_node) {return NULL;}
        return top_node;
    }

private:
    StackNode *top_node{nullptr};

};
#include <concepts>
#include <stdexcept>
#include <iostream>


template <class T>
class Stack {
protected:
    class StackNode {
    friend class Stack;
    private:
        T _data;
        StackNode *next{nullptr};
    public:
        StackNode() : _data{0}, next{nullptr}
        {}

        StackNode(const T& data) : _data{data}, next{nullptr}
        {}

        T data() {
            return _data;
        }
    };

    StackNode *top_node{nullptr};

public:

    void push(const T& data) {
        StackNode* new_node{new StackNode(data)};
        StackNode* tmp = top_node;
        top_node = new_node;
        new_node->next = tmp;
        return;
    }

    StackNode* top() {
        if (!top_node) {return NULL;}
        return top_node;
    }

    T pop() {
        if (!top_node) {
            throw std::runtime_error("Stack is empty");
        }
        // return top node and remove it
        T data = top_node->data();
        StackNode* tmp = top_node;
        top_node = top_node->next;
        delete tmp;
        return data;
    }
};

int main()
{
    Stack<int>* stacky = new Stack<int>();
    stacky->push(1);
    stacky->push(2);
    stacky->push(3);
    stacky->push(4);
    // stacky->pop();
    std::cout << stacky->pop() << " " << std::endl;
    std::cout << stacky->pop() << " " << std::endl;
    std::cout << stacky->pop() << " " << std::endl;
    stacky->push(5);
    std::cout << stacky->pop() << " " << std::endl;
    std::cout << stacky->pop() << " " << std::endl;
    std::cout << stacky->pop() << " " << std::endl;
    // std::cout << stacky->top_node;
    
    return 0;
}
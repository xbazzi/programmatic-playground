#include <concepts>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cstdint>


template <class T>
class Stack {
private:
    class StackNode {
    friend class Stack;
    private:
        T _data;
    protected:
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

    T _last_min{std::numeric_limits<T>::max()};   
    uint32_t _size{0};
    StackNode *top_node{nullptr};

public:

    uint32_t size() {
        return _size;
    }

    bool hasNext() 
    {
        return this->top() && this->top()->next;
    }

    void push(const T& data) {
        _last_min = std::min(data, _last_min);
        StackNode* new_node{new StackNode(data)};
        StackNode* tmp = top_node;
        top_node = new_node;
        new_node->next = tmp;
        _size++;
        return;
    }

    StackNode* top() {
        if (!top_node) return nullptr;
        return top_node;
    }

    T min() {
        return _last_min;
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
        _size--;
        return data;
    }
};

// int main()
// {
//     Stack<int>* stacky = new Stack<int>();
//     // stacky->push(1);
//     stacky->push(2);
//     std::cout << "min: " << stacky->min() << std::endl;
//     stacky->push(3);
//     stacky->push(4);
//     // stacky->pop();
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
//     stacky->push(1);
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
//     stacky->push(0);
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
//     stacky->push(1);
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
//     stacky->push(0);
//     std::cout << stacky->pop() << " " << stacky->min() << std::endl;
    
//     return 0;
// }
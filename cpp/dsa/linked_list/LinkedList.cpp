/// Author:  Alexander Bazzi
/// Description: Implementation of a singly linked-list

#include <iostream>
#include <array>

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data, Node* next = nullptr) : data(data), next(next) {}
};

template<typename T>
class LinkedList
{
    private:
    Node<T>* head;

    public:
    explicit LinkedList() : head(nullptr) {}

    LinkedList(LinkedList<T>&& other) noexcept : head(other.head) {
        /// @todo is this freeing the memory pointed to by other.head?
        other.head = nullptr;
    }

    // Move assignment operator
    LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
        if (this != &other) {
            delete head; // Clean up current resources
            head = other.head; // Transfer ownership
            other.head = nullptr; // leave the previous head in a valid state
        }
        return *this;
    }

    void insertEnd( T data ) {
        Node<T>* newNode = new Node<T>(data);
        if( head == nullptr ) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while( current->next != nullptr ) {
               current = current->next;
            }
            current->next = newNode;
        }
    }

    Node<T>* reverseOrder() {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;

        while(current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }

    void printList() const {
        Node<T>* current = head;
        while(current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};
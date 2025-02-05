/// Author:  Alexander Bazzi
/// Description: Implementation of a singly linked-list

#include <iostream>
#include <memory>

template <typename T>
class Node {
public:
    Node* next;

    Node(T data, Node* next = nullptr) : data(data), next(next) {}

    /// @brief Returns the data member
    /// @return data
    auto get_val() -> int {
        return this->data;
    }

private:
    T data;
};

template <typename T>
class LinkedList
{
    private:

    public:
    Node<T>* head;

    explicit LinkedList() : head(nullptr) {}

    /// @brief Move operator
    /// @param other 
    LinkedList(LinkedList<T>&& other) noexcept : head(other.head) {
        other.head = nullptr;
    }

    /// @brief Move assignment operator
    /// @param other 
    /// @return 
    LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
        if (this != &other) {
            delete head; // Clean up current resources
            head = std::move(&other->head); // Transfer ownership
            other.head = nullptr; // leave the previous head in a valid state
        }
        return *this;
    }

    void insert_end(T data) {
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

    Node<T>* reverse_order() {
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


    void print_list() const {
        Node<T>* current = head;
        while(current != nullptr) {
            std::cout << current->get_val() << " ";
            current = current->next;
        }
    }
};
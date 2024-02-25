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

int main()
{
    // create a linked list of ints
    LinkedList<int> list = LinkedList<int>();

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);

    list.printList();
    list.reverseOrder();
    list.printList();
}
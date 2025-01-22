package linkedlist

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
}

func (ll *LinkedList) Print() {
	if ll.head == nil {
		fmt.Println("List is empty.")
		return
	}
	current := ll.head
	for current != nil {
		fmt.Printf("%d -> ", current.value)
		current = current.next
	}
	fmt.Println("nil")
}

func (ll *LinkedList) Insert(newVal int) {
	var newNode *Node = &Node{value: newVal, next: nil}
	if ll.head == nil {
		ll.head = newNode
		return
	}

	var current *Node = ll.head
	for current.next != nil {
		current = current.next
	}
	current.next = newNode
}

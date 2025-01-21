package main

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

func main() {
	ll := LinkedList{}
	fmt.Print("At first, ")
	ll.Print()

	fmt.Print("Then: ")
	ll.Insert(30)
	ll.Insert(31)
	ll.Insert(32)
	ll.Insert(33)
	ll.Insert(34)
	ll.Print()

}

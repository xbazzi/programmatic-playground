package main

import (
	"fmt"

	"xbazzi.com/xbazzilib"
)

func main() {

	//xbazzilib.LinkedList{}
	ll := xbazzilib.LinkedList{}
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

package main

import (
	"errors"
	"fmt"
	"my-first-project/logger"
	//"logger/logger.go"
	//"math"
	//"math/rand"
	//"sync"
	//"time"
)

// Struct, similar to a class
type Point struct {
	x, y uint16
}

type SomeStruct struct {
	z, a uint32
	arr  []int
}

func newPoint(x, y uint16) Point {
	return Point{x, y}
}

func doSomething() (int, error) {
	error := errors.New("did something alright")
	var x uint16 = 40
	if x == 40 {
		return 1, error
	}
	return int(x), nil
}

func main() {
	//log.Logger()
	fmt.Println("hello universe")
	//var x []byte{}
	var z int
	var err error
	z, err = doSomething()
	z = z + 1
	fmt.Println("error is ", err)
	//y := uint16(30)
	//logger.LogSumn()
	fmt.Println(logger.LogSumn("we done goofed, sir!"))
}

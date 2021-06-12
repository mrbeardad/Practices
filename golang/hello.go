package main

import (
	"fmt"
	"hello/pkgA"
)

type Type struct {
    name string
    id   int
}

func (self Type) modify() {
    self.id += self.id + 1
}

func main2() {
    t := Type{}
    (&t).modify()
    print(t.id)
    print(pkgA.PI)
    print()
}

func main1() {
    var mapped map[string]int
    mapped = make(map[string]int)
    mapped["fuck"] = 1
    fmt.Println(mapped)
    mapCopy := mapped
    mapCopy["you"] = 2
    fmt.Println(mapped)
    fmt.Println(mapCopy)
    mapped = map[string]int{"man": 3}
    fmt.Println(mapped)
    fmt.Println(mapCopy)
}

package main

import "fmt"

func main() {
    // s := "string"
    // a := [...]int{1, 2, 3}
    // l := []int{0, 1, 2}
    // m := map[string]int{"a": 1, "b": 2}
    // c := make(chan int)
    // println(s)
    // println(a)
    // println(l)
    // println(m)
    // println(c)
    var s1, s2 int
    n, ok := fmt.Sscanf("11 22 ", " %d%d\n", &s1, &s2)
    fmt.Printf("%v|%v|%v|%v\n", n, ok, s1, s2)
}

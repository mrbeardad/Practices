package main

import (
    "fmt"
    "testing"
    . "github.com/smartystreets/goconvey/convey"
)

func rangetest() {
    s := []int{1,2,3,4,5}
    for idx, val := range s {
        if idx == 1 {
            s[idx + 1]++
            s = append(s, 1)
        }
        fmt.Print(val, " ")
    }
    fmt.Printf("\ns: %v", s)

    a := [...]int{6,7,8,9,10}
    for idx, val := range a {
        if idx == 1 {
            a[idx + 1]++
        }
        fmt.Print(val, " ")
    }
    fmt.Printf("\na: %v", a)
}

func intf() {
    var i interface{}
    impl := []int{1}
    i = impl
    impl = append(impl, 2)
    fmt.Println(i, impl)
}

func TestRange(test *testing.T) {
    SetDefaultFailureMode(FailureContinues)
    defer SetDefaultFailureMode(FailureHalts)

    Convey("", test, func() {
        intf()
    })
}

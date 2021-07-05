package main

import (
    "fmt"
    "testing"
    . "github.com/smartystreets/goconvey/convey"
)

func TestCase(test *testing.T) {
    SetDefaultFailureMode(FailureContinues)
    defer SetDefaultFailureMode(FailureHalts)
    Convey("Outer", test, func() {
        So(fmt.Sprint("fuck"), ShouldEqual, "fuck")
        So(fmt.Sprint("fuck"), ShouldEqual, "fuck")
        Convey("Inner", func() {
            So(1., ShouldAlmostEqual, 0.99999, .0001)
        })
    })
}

package main

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func fib(n int) int {
    if n < 2 {
        return n
    }
    fim1, fi := 0, 1
    for i := 1; i < n; i++ {
        fip1 := fi + fim1
        fim1 = fi
        fi = fip1
    }
    return fi
}

func TestFib(test *testing.T) {
    SetDefaultFailureMode(FailureContinues)
    defer SetDefaultFailureMode(FailureHalts)
    Convey("Equality assertions should be accessible", test, func(){
        So(fib(1), ShouldEqual, 0)
        So(fib(0), ShouldEqual, 0)
    })
} 

package main

import (
    "testing"
)

func TestFib(test *testing.T) {
    if Fib(0) != 0 {
        test.Errorf("Fib(0) == 0: Failed")
    }
    if Fib(1) != 0 {
        test.Errorf("1")
    }
}

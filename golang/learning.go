package main

func Fib(n int) int {
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

package pkgA

const PI = 3.14

func Test() int {
    v1 := 1
    v1, v2 := 2, 3
    print(&v1)
    return v1 + v2
}

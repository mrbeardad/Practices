package main

import (
	"flag"
	"fmt"
	"time"

	"gitee.com/liyunmy/go-hello/src/userinfo"
)

var _ = fmt.Errorf

type Reader interface {
    Read()
}

type Writer interface {
    Write()
    Read()
}

type ReadWriter interface {
    Reader
    Writer
}

type MyReader struct {}
type MyWriter struct {}
type MyReadWriter struct {
    MyReader
    *MyWriter
}

func (self *MyReader) Read() {
    fmt.Println("MyReader.Read")
}

func (self *MyWriter) Write() {
    fmt.Println("MyWriter.Write")
}

// func (self *MyReadWriter) Read() {
//     fmt.Println("MyReadWriter.Read")
// }
//
// func (self *MyReadWriter) Write() {
//     fmt.Println("MyReadWriter.Write")
// }

func testInherit() {
    r, w, rw := MyReader{}, MyWriter{}, MyReadWriter{}
    r.Read()
    w.Write()
    rw = MyReadWriter{r, &w}
    rw.Read()
    rw.Write()
    // var rdwt Reader
    // rdwt = rw
    // print(rdwt)
}

type If interface {
    m1()
    m2()
}

type Dv int

func (self Dv) m1() {}

func (self *Dv) m2() {}

func testPolymorphic() {
    var i If
    var d Dv
    i = &d
    print(i)
}

func testFlag() {
    pName := flag.String("n", "", "usage info")
    pO := flag.String("o", "", "usage info")
    fmt.Print(*pName)
    fmt.Print(*pO)
    var I = 2
    fmt.Print(I)
}

var I  = 1

func testType() {
    type Int int
    type IInt Int
    type Integer int
    var ig Integer = 1
    var it int = int(ig)
    print(it)
    type Seq []int
    s := []int{1}
    var _ Seq = []int{}
    var _ Seq = s
    const A int = 1 << 31
    const B = 2
    var _ int = A

    type C struct {
        i int
    }
    type CC C

    a := [...]int{0, 1, 2}
    si := a[1:2]
    fmt.Println(len(si), cap(si))
}

type Inter interface {
    Get() string
    Set(string)
}

type A struct {
    name string
}
type C struct {
    A
}

func (this *A) Get() string {
    return this.name
}

func (this *A) Set(newName string) {
    this.name = newName
}

func testInterfacePtrVal() {
    a := A{"xiong"}
    var i Inter = &a
    a.Set("bear")
    fmt.Println(i.Get(), a.Get())

    c := C{A: A{"name"}}
    c.Get()

    s := "hello"
    ss := &s
    s = "fuck"
    fmt.Println(s, *ss)
}

func testChannel() {
    var ch chan int
    ch = make(chan int)
    go func () {
        ch <- 1
    }()
    a, ok := <-ch
    fmt.Println(a, ok)
    a, ok = <-ch
    fmt.Println(a, ok)
    switch 1 {
    case 1:
        var i int
        fmt.Println(i)
    case 2:
        fmt.Println()
    }

    s := []int{0, 1, 2}
    s = s[:2]
    s = append(s, 3, 4)
    fmt.Println(s)
}

func testChan() {
    sign := make(chan struct{})
    for i := 0; i < 10; i++ {
        go func() {
            <-sign
            fmt.Println(i)
            sign<-struct{}{}
        }()
    }
    sign<-struct{}{}
    <-sign
    const i = 1 << 511
    const f = i * 1e65535
}

func testVaridict() {
    f := func(args... int) {
        s := args
        fmt.Println(s)
    }
    s := []int{0, 1, 2}
    f(s...)

}

func testCvt() {
    _, ch2 := make(chan int), make(chan int)
    ch3 := ch2
    fmt.Println(ch3 == ch2)
    f := 1.0
    f++
    fmt.Println(&ch2 == &ch3)
    var b rune = '熊'
    fmt.Println(b)
    type A struct {
        name string "nani"
    }
    var a A
    fmt.Println(a.name)
}

func main3() {
    for i := 0; i < 10; i++ {
        go func() {
            println(i)
        }()
    }
    time.Sleep(time.Second)
    type Int int
    var ii int
    var i Int = Int(ii)
    print(i)
    switch 1 {
    case 2, func() int {print(1);return 2}():
    }
}

func main11() {
    userinfo.UserLogin()
    type A []int
    type AA A
    var _ A = []int{1}
    var a AA = []int{1}
    var _ []int = a
    type S struct {
        i int
    }
    type SS S
    println(&struct{}{})
    println(&struct{}{})
    ch := make(chan int)
    close(ch)
    for range ch {
        println("in")
    }
}

func v(args... int) {
    ;
}

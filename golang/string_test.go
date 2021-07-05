package main

import (
	"fmt"
	"strings"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func testString(test *testing.T) {
    str := "dj熊海成s"
    fmt.Println(strings.IndexRune(str, 'd'))
    fmt.Println(strings.IndexRune(str, '熊'))
    fmt.Println(strings.IndexRune(str, 's'))
}

func testDayJ(test *testing.T) {
    var year, month, day int
    fmt.Scan(&year, &month, &day)
    mdays := [12]int{31,28,31,30,31,30,31,31,30,31,30,31}
    if year % 4 == 0 && year % 100 != 0 || year % 400 == 0 {
        mdays[1] += 1
    }
    j := 0
    for thisMon := 0; thisMon < month - 1; thisMon++ {
        j += mdays[thisMon]
    }
    j += day
    fmt.Printf("%04d-%02d-%02d : %03d days", year, month, day, j)
}

func testScan(test *testing.T) {
    var ls []byte
    n, err := fmt.Scan(&ls)
    if err != nil {
        fmt.Println(err.Error(), n)
    } else {
        fmt.Println(ls)
    }
}

func TestBytes(test *testing.T) {
    str := "dj熊bb"
    fmt.Println(str[0], str[3])
}

func testConvey(test *testing.T) {
    Convey("TestConvey", test, func() {
        So(1, ShouldEqual, 2)
    })
}

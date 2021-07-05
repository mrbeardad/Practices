package main

import (
    "testing"
    . "github.com/smartystreets/goconvey/convey"
)

func qsort(data []int) []int {
    if len(data) < 2 {
        return data
    }
    left, right := 0, len(data) - 1
    mid := (left + right) / 2
    if data[left] < data[right] {
        data[right], data[left] = data[left], data[right]
    }
    if data[mid] < data[right] {
        data[mid], data[right] = data[right], data[left]
    }
    if data[mid] < data[left] {
        data[mid], data[left] = data[left], data[mid]
    }
    data[left], data[right] = data[right], data[left]
    pivot := data[right]

    for {
        for left++; data[left] < pivot; left++ {}
        for right--; data[right] > pivot; right-- {}
        if left >= right {
            break
        }
        data[left], data[right] = data[right], data[left]
    }
    data[left], data[len(data) - 1] = data[len(data) - 1], data[left]
    qsort(data[0:left])
    qsort(data[left + 1:])
    return data
}

func TestQsort(test *testing.T) {
    SetDefaultFailureMode(FailureContinues)
    defer SetDefaultFailureMode(FailureHalts)

    Convey("Test QuickSort", test, func() {
        So(qsort([]int{9,8,7,5,2,3,6,4,1,0}), ShouldResemble, []int{0,1,2,3,4,5,6,7,8,9})
        So(qsort([]int{}), ShouldResemble, []int{})
        So(qsort([]int{1}), ShouldResemble, []int{1})
        So(qsort([]int{2,1}), ShouldResemble, []int{1,2})
    })
}

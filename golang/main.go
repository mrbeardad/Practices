package main

import (
	"fmt"
)

func main() {
    var text, pattern string
    // for {
        // if _, err := fmt.Scan(&text, &pattern); err != nil {
            // fmt.Println(err.Error())
            // return
        // }
        // fmt.Println(regexp.MustCompile(pattern).ReplaceAllString(text, "\033[31;4m$0\033[m"))
    // }
    fmt.Println(text + pattern)
}

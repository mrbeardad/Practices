package main

import (
	"fmt"

	"hello/greetings"
)


func main() {
    message := greetings.Hello("Heache")
    fmt.Println(message)
}

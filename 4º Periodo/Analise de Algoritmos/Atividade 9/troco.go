package main

import "fmt"

func main() {

	var moedas = []int{1, 5, 10, 25, 50}
	in := 74
	index := 4
	for in >= 0 {
		if in-moedas[index] >= 0 {
			in -= moedas[index]
		} else {
			index -= 1
		}
	}

	fmt.Println(in)
}

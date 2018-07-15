package main

import (
	"fmt"
)

func singleNumber(arr []int) int {
	result := 0
	for _, num := range arr {
		result ^= num
	}
	return result
}

func main() {
	var single int
	arr := []int{1, 2, 2}
	single = singleNumber(arr)
	fmt.Println(single)
}

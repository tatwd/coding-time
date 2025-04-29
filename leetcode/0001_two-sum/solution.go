package main

import "fmt"

func twoSum(nums []int, target int) []int {
	res := []int{-1, -1}
	numsMap := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if v, ok := numsMap[target-nums[i]]; ok {
			res[0] = v
			res[1] = i
			break
		}
		numsMap[nums[i]] = i
	}
	return res
}

func main() {
	res := twoSum([]int{2, 7, 11, 15}, 9)
	fmt.Println(res)
}

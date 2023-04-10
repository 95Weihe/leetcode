package main

import "sort"

/**
组合总和
*/
func combinationSum(candidates []int, target int) [][]int {
	if len(candidates) == 0 {
		return [][]int{}
	}
	c, res := []int{}, [][]int{}
	findcombinationSum(candidates, target, 0, c, &res)
	sort.Ints(candidates)

	return res
}

func findcombinationSum(nums []int, target, index int, c []int, res *[][]int) {
	
}

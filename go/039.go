package main

import "sort"

/**
组合总和  回溯 + 剪枝
*/
func combinationSum(candidates []int, target int) [][]int {
	if len(candidates) == 0 {
		return [][]int{}
	}
	var c []int
	var res [][]int
	sort.Ints(candidates)
	dfsSum(candidates, target, 0, c, &res)
	return res
}

func dfsSum(nums []int, target, index int, c []int, res *[][]int) {
	if target <= 0 {
		if target == 0 {
			b := make([]int, len(c))
			copy(b, c)
			*res = append(*res, b)
		}
		return
	}
	for i := index; i < len(nums); i++ {
		if target-nums[i] < 0 {
			break
		}
		c = append(c, nums[i])
		dfsSum(nums, target-nums[i], i, c, res)
		c = c[:len(c)-1]
	}
}

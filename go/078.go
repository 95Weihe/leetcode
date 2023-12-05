package main

/**
子集
求数组所有的子集 不重复
经典回溯
循环递归，注意遍历元素 以及结果退回
*/
var r [][]int

func subsets(nums []int) [][]int {
	r = make([][]int, 0)
	path := make([]int, 0)
	f(nums, 0, path)
	return r
}

func f(nums []int, idx int, path []int) {
	t := make([]int, len(path))
	copy(t, path)
	r = append(r, t)
	for i := idx; i < len(nums); i++ {
		path = append(path, nums[i])
		idx++
		f(nums, idx, path)
		path = path[:len(path)-1]
	}
}

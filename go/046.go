package main

/**
思路：回溯递归，按照全排列性质去递归即可，每个元素只用一次用 used 数组记录即可。
*/
func permute(nums []int) [][]int {
	path := make([]int, len(nums))
	result, used := make([][]int, len(nums), len(nums)), make([]bool, len(nums), len(nums))
	permuteDfs(nums, path, &result, &used)
	return result
}

func permuteDfs(nums []int, path []int, result *[][]int, used *[]bool) {
	if len(path) == len(nums) {
		l := make([]int, len(path))
		copy(l, path)
		*result = append(*result, l)
		return
	}
	for i := 0; i < len(nums); i++ {
		if !(*used)[i] {
			(*used)[i] = true
			path = append(path, nums[i])
			permuteDfs(nums, path, result, used)
			path = (path)[:len(path)-1]
			(*used)[i] = false
		}
	}
}

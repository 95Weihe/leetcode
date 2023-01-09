package main
/*
	给定一个整数数组 nums 和一个整数目标值 target，
	请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
	2 7 11 5      9
*/
func twoSum(nums []int, target int) []int {
	table := make(map[int]int)
	for i, v := range nums {
		if k, ok := table[target-v]; ok {
			return []int{k, i}
		}
		table[v] = i
	}
	return nil
}

package main

/**
在排序数组中查找元素的第一个和最后一个位置
思路：二分找到元素，往后推出右边坐标即可
*/
func searchRange(nums []int, target int) []int {
	l, r, err := 0, len(nums)-1, []int{-1, -1}
	if r == -1 {
		return err
	}
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if nums[l] != target {
		return err
	}
	var i int
	for i = l; i < len(nums) && nums[i] == nums[l]; i++ {
	}
	return []int{l, i - 1}
}

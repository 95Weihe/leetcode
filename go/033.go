package main

/**
搜索旋转排序数组
思路：排序 ->  二分
二分找到断开的点，然后根据target的值判断在那个区间，接着在该区间二分搜索即可。
*/
func search(nums []int, target int) int {
	len := len(nums)
	if len == 0 {
		return -1
	}
	l, r := 0, len-1
	for l < r {
		mid := (l + r + 1) >> 1
		if nums[mid] >= nums[0] {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if target >= nums[0] {
		l = 0
	} else {
		l = r + 1
		r = len - 1
	}
	for l < r {
		mid := (l + r) >> 1
		if nums[mid] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if nums[r] == target {
		return r
	} else {
		return -1
	}
}

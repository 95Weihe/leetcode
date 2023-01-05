package main

import "sort"

/**
给你一个整数数组 nums ，判断是否存在三元组之和为0且不重复。
思路：排序 + 双指针
-1,0,1,2,-1,-4   ->  -4,-1,-1,0,1,2
排序数组，然后遍历每个元素，为每个元素匹配条件sum == 0，使用双指针sum = s[i] + s[l] + s[r]
sum > 0 r--
sum < 0 l++
*重复元素跳过 写if时考虑要周全
*/
func threeSum(nums []int) [][]int {
	res, n := make([][]int, 0), len(nums)
	sort.Ints(nums)
	if n < 2 || nums[0] > 0 {
		return nil
	}
	for i := 0; i < n; i++ {
		l, r := i+1, n-1
		for i < n-1 && nums[i] == nums[i+1] {
			i++
		}
		for l < r {
			sum := nums[i] + nums[l] + nums[r]
			if sum < 0 {
				l++
			} else if sum > 0 {
				r--
			} else {
				res = append(res, []int{nums[i], nums[l], nums[r]})
				for l < r && nums[l] == nums[l+1] {
					l++
				}
				for l < r && nums[r] == nums[r-1] {
					r--
				}
				l++
				r--
			}
		}
	}
	return res
}

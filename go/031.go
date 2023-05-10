package main

/**
整数数组的下一个排列是指其整数的下一个字典序更大的排列。
给你一个整数数组nums，找出 nums 的下一个排列
必须原地修改，只允许使用额外常数空间
思路：[8,9,6,10,7,2]，从后往前找，找到较小的数6，然后再找到较大的7，交换位置，再将较大的数之后的序列升序。
交换完之后较大数之后的区间为降序区间，只需反转即可。
*/
func nextPermutation(nums []int) {
	k := len(nums) - 1
	for ; k > 0 && nums[k-1] > nums[k]; k-- {
	}
	if k <= 0 {
		reverse(&nums, 0, len(nums)-1)
	} else {
		t := k
		for ; t < len(nums) && nums[k-1] < nums[t]; t++ {
		}
		swap(&nums, k-1, t-1)
		reverse(&nums, k, len(nums)-1)
	}
}

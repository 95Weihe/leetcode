package main

/**
接雨水
思路：双指针遍历 + 贪心计算容量
如何合并指针：左右两边靠拢，移动条件：一个点，一边计算容量时另一边肯定要有个高的，这样才能保证计算时水可以装下
所以 l <= r 左边计算 反则右边计算
如何计算: 就是走过的最大值 - 当前高度，一格一格累加即可，因为可以保证每格都可遍历到。
*/
func trap(height []int) int {
	l, r, ml, mr, res := 0, len(height), 0, 0, 0
	for l <= r {
		if height[l] <= height[r] {
			if height[l] > ml {
				ml = height[l]
			} else {
				res += ml - height[l]
			}
			l++
		} else {
			if height[r] > mr {
				mr = height[r]
			} else {
				res += mr - height[r]
			}
			r--
		}
	}
	return res
}

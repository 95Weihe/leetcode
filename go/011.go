package main

/**
给定一个长度为 n 的整数数组 height 。
有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
思路：双指针 + 贪心，从两边向中间靠拢，取最大值即可。移动小的指针（短板效应）。
*/
func maxArea(height []int) int {
	res := 0
	for i, j := 0, len(height)-1; i < j; {
		h, l := 0, j-i
		if height[i] < height[j] {
			h = height[i]
			i++
		} else {
			h = height[j]
			j--
		}
		area := l * h
		res = max(area, res)
	}
	return res
}

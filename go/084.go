package main

/**
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
思路：单调栈  从左往右遍历 维护一个单调递增的栈 遇到比栈顶小的 开始求栈内元素面积 直到比他大的全部弹出 然后压入该元素
由于单调栈的缘故 栈内元素的面积 宽度就是 i 与 栈内上一个元素的的距离
由于是单调栈 栈内相邻两个下标内不会出现凹陷(1 4 -> 2和3的值不会小于4的值 所以 面积是 4的值*3) 所以可以求出面积
然后遍历过程维护好单调栈的性质
 2
heights = [2,1,5,6,2,3]
[2,4]
*/
func largestRectangleArea(heights []int) int {
	maxArea := 0
	n := len(heights) + 2
	// Add a sentry at the beginning and the end
	getHeight := func(i int) int {
		if i == 0 || n-1 == i {
			return 0
		}
		return heights[i-1]
	}
	// 定义栈
	stk := make([]int, 0, n/2)
	// 从左往右遍历
	for i := 0; i < n; i++ {
		// 找出栈内比 i 大的元素 依次求面积
		for len(stk) > 0 && getHeight(stk[len(stk)-1]) > getHeight(i) {
			idx := stk[len(stk)-1]
			// pop
			stk = stk[:len(stk)-1]
			maxArea = max(maxArea, getHeight(idx)*(i-stk[len(stk)-1]-1))
		}
		stk = append(stk, i)
	}
	return maxArea
}

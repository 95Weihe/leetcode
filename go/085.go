package main

/**
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
找出每个元素左边连续1的个数 然后f[i][j] 将会有 j 个 柱状图 ，柱子高度就是1的个数
由于都是左边连续的1就可对应起来 使用单调栈求出每个柱状图的最大矩形面积即可
*/

func maximalRectangle(matrix [][]byte) int {
	maxArea := 0
	n, m := len(matrix), len(matrix[0])
	left := make([][]int, n)
	for i := 0; i < n; i++ {
		left[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == 1 {
				if j == 0 {
					left[i][j] = 1
				} else {
					left[i][j] = left[i][j-1] + 1
				}
			}
		}
	}
	n = n + 2
	for j := 0; j < m; j++ {
		getHeight := func(i int) int {
			if i == 0 || n-1 == i {
				return 0
			}
			return left[i-1][j]
		}
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
	}
	return maxArea
}

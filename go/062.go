package main

/**
不同路径
in:  m = 3, n = 7
out: 28
思路：到达最后一步的路径为上面和左边之和
动态规划 f[m][n] 状态：00 - mn的路径  属性：数量
转移方程：f[m][n] = f[m-1][n] + f[m][n-1]
初值：f[0][i] f[i][0] = 1
*/
func uniquePaths(m int, n int) int {
	f := make([][]int, m)
	for i := 0; i < len(f); i++ {
		f[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		f[i][0] = 1
	}
	for i := 0; i < n; i++ {
		f[0][i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[i][j] = f[i-1][j] + f[i][j-1]
		}
	}
	return f[m-1][n-1]
}

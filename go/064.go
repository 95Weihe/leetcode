package main

/**
最小路径和
请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
in： grid = [[1,3,1],[1,5,1],[4,2,1]]
out：7
思路：动态规划
动态规划 f[m][n] 状态：11 - mn的路径  属性：min(和)
转移方程：f[m][n] = f[m-1][n] + f[m][n-1]
初值：f[0][i] f[i][0] = 1
*/

// MaxValue 0 <= grid[i][j] <= 200
var MaxValue int = 201

func minPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m+1)
	for i := 0; i < len(f); i++ {
		f[i] = make([]int, n+1)
	}

	for i := 0; i <= m; i++ {
		f[i][0] = MaxValue
	}
	for i := 0; i <= n; i++ {
		f[0][i] = MaxValue
	}
	f[0][1] = 0
	f[1][0] = 0
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i-1][j-1]
		}
	}
	return f[m][n]
}

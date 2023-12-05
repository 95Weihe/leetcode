package main

/**
编辑距离
给你两个单词word1和word2， 请返回将word1转换成word2所使用的最少操作数。
插入 删除 替换
经典线性dp
状态 f[i][j] 0-i 转移到 0-j 的最小操作数
属性 min(操作数)
注：目标状态如何从前面状态转移过来的，转移方程得覆盖所有情况
i,j => i-1,j-1(s[i] != s[j] 操作数+1) || i-1,j (操作数+1) || i,j-1 (操作数+1)
转移方程 f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1)
初值 f[0][0-j] = j  f[0-i][0] = i 一个字符串长度为0，另一个的长度即为操作次数
*/
func minDistance(word1 string, word2 string) int {
	n, m := len(word1), len(word2)
	f := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]int, m+1)
	}
	for i := 0; i <= n; i++ {
		f[i][0] = i
	}
	for i := 0; i <= m; i++ {
		f[0][i] = i
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			f[i][j] = min(f[i-1][j], f[i][j-1]) + 1
			if word1[i-1] == word2[j-1] {
				f[i][j] = min(f[i][j], f[i-1][j-1])
			} else {
				f[i][j] = min(f[i][j], f[i-1][j-1]+1)
			}
		}
	}
	return f[n][m]
}

package main

/**
旋转图像
思路: 对角线翻转 + 竖轴翻转
*/
func rotate(matrix [][]int) {
	l := len(matrix)
	for i := 0; i < l; i++ {
		for j := i + 1; j < l; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
	for i := 0; i < l; i++ {
		for j := 0; j < l/2; j++ {
			matrix[i][j], matrix[i][l-j-1] = matrix[i][l-j-1], matrix[i][j]
		}
	}
}

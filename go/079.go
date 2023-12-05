package main

/**
单词搜索
二位字符网格中寻找字符串  连续 不重复
思路：dfs 回溯
*/
func exist(board [][]byte, word string) bool {
	visited := make([][]bool, len(board))
	for i := 0; i < len(visited); i++ {
		visited[i] = make([]bool, len(board[0]))
	}
	for i, v := range board {
		for j := range v {
			if d(board, visited, word, i, j, 0) {
				return true
			}
		}
	}
	return false
}

func d(board [][]byte, visited [][]bool, word string, x, y, idx int) bool {
	n, m := len(board), len(board[0])
	if idx == len(word)-1 {
		return board[x][y] == word[idx]
	}
	// 上右下左搜索
	dx, dy := []int{-1, 0, 1, 0}, []int{0, 1, 0, -1}
	if board[x][y] == word[idx] {
		visited[x][y] = true
		for i := 0; i < 4; i++ {
			ix, iy := x+dx[i], y+dy[i]
			f := ix >= 0 && ix < n && iy >= 0 && iy < m
			if f && d(board, visited, word, ix, iy, idx+1) {
				return true
			}
		}
		visited[x][y] = false
	}
	return false
}

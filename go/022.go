package main

/*
括号生成 数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。
思路：n个左括号和右括号的全排列，然后看是否符合括号匹配。
全排列 + 是否匹配
双递归 递归确定左括号然后递归确定右括号l r，优先确定左括号，然后当有左括号放的前提下可放右括号
左括号 l > 0
右括号 l < r
*/

func generateParenthesis(n int) []string {
	res := make([]string, 0)
	if n == 0 {
		return res
	}
	find(n, n, "", &res)
	return res
}
func find(l, r int, s string, res *[]string) {
	if l == 0 && r == 0 {
		*res = append(*res, s)
		return
	}
	if l > 0 {
		find(l-1, r, s+"(", res)
	}
	if l < r {
		find(l, r-1, s+")", res)
	}
}

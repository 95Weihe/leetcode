package main

/**
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度
思路：使用栈，首先记录一个初始坐标，每次非法括号就更新该坐标，初值为-1。
)()())  stack -1 0 5; res = i - stack[len - 1]
)))())()()  stack -1 0 1 2 5
*/

func longestValidParentheses(s string) int {
	var stack []int
	res := 0
	stack = append(stack, -1)
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, i)
		} else {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
			} else {
				res = max(res, i-stack[len(stack)-1])
			}
		}
	}
	return res
}

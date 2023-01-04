package main

/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
答案可以按任意顺序返回。
思路：回溯，递归结束后恢复现场
递归结束条件：digits内容为空
子递归选择：每一次的可选择
*/
var res []string
var letter = map[string]string{
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
}

func letterCombinations(digits string) []string {
	res = make([]string, 0)

	if len(digits) == 0 {
		return res
	}
	dfs("", digits)
	return res
}
func dfs(s string, digits string) {
	if digits == "" {
		res = append(res, s)
		return
	}
	idx := digits[0:1]
	digits = digits[1:]
	for i := 0; i < len(letter[idx]); i++ {
		s += string(letter[idx][i])
		dfs(s, digits)
		s = s[0 : len(s)-1]
	}
}

func main() {
	//case1: "23"
	res := letterCombinations("23")
	println(res)
}

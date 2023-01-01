package main

/**
给你一个字符串 s，找到 s 中最长的回文子串。
思路：DP，时间复杂度 O(n^2)，空间复杂度 O(n^2)
f[i][j]表示i-j为回文串，即s[i-1] == s[j+1] 的时候f[i-1][j+1]也是。
表达式为:f[i-1][j+1] == (s[i-1] == s[j+1]) && ((j - i < 3) || f[i][j])
babad
*/
func longestPalindrome(s string) string {
	res, f := "", make([][]bool, len(s))
	for i := 0; i < len(s); i++ {
		f[i] = make([]bool, len(s))
	}
	for i := len(s) - 1; i >= 0; i-- {
		for j := i; j < len(s); j++ {
			f[i][j] = (s[i] == s[j]) && ((j-i < 3) || f[i+1][j-1])
			if f[i][j] && (res == "" || j-i+1 > len(res)) {
				res = s[i : j+1]
			}
		}
	}
	return res
}

func main() {
	// case1 : "babad" -> bab/aba  case2: "cbbd" -> bb
	s := "babad"
	res := longestPalindrome(s)
	println(res)
}

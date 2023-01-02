package main

/**
请实现一个函数用来匹配包含'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"abaca"匹配，但与"aa.a"和"ab*a"均不匹配。

思路：字符串匹配一般使用动态规划
状态表示：f[i][j]表示s从i到结尾与p从j到结尾匹配
状态转移：'.'与任何字符匹配  bool = p[j] == '.' || s[i] == p[j] 就是代表字符相等
当p[j+1] == '*'时 f[i][j] = f[i][j+2] || (bool && f[i+1][j])
	两种情况，1 当'*'后面的都与之匹配显然会全部匹配；2 当i+1匹配的时候且字符相等时显然也全部匹配。
当p[j+1] != '*'时 显然字符相等就是匹配。f[i][j] == bool && f[i+1][j+1]
tip: *结尾时，判断时需要前一个状态所以在s和p后加个空格增加判断位，不影响结果。
*/
func isMatch(s string, p string) bool {
	s, p = s+" ", p+" "
	n, m := len(s), len(p)
	f := make([][]bool, n+1)
	for i := 0; i <= n; i++ {
		f[i] = make([]bool, m+1)
	}
	f[n][m] = true
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			flag := p[j] == '.' || s[i] == p[j]
			if j+1 < m && p[j+1] == '*' {
				f[i][j] = f[i][j+2] || (flag && f[i+1][j])
			} else {
				f[i][j] = flag && f[i+1][j+1]
			}
		}
	}
	return f[0][0]
}

func main() {
	//case1: 'aa' 'a*'  case2: 'aa'  '.*'
	s, p := "aa", "a*"
	res := isMatch(s, p)
	println(res)
}

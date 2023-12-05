package main

/**
最小覆盖子串
字符串 s t 从 s 的子串中找出包含 t 中所有字符的最小字串 一对一
全英文
暴力：每个字串进行比较
滑动窗口：维护窗口  一般用于匹配
i j 窗口左右边界
窗口在 s 上滑动，左边固定，j 移动直到窗口含有 t 的所有字符，
尝试移动 i 使得窗口依旧符合要求
判断是否符合要求 使用哈希表记录，每个字符的个数
技巧：存入 t 的字符，出现一次 -1，窗口每次滑动时 +1
这样没有匹配时该字符不是匹配字符是 >0 是的话 <= 0
这样记录每次匹配的次数 如果 cnt == len(t) 即代表窗口包含t所有字符
按照思路 该移动 i 了 如果不是匹配字符即可移动 即 >0
最后取最小字符串即可
*/
func minWindow(s string, t string) string {
	n, m := len(s), len(t)
	hash := [128]int{}
	for _, v := range t {
		hash[v]--
	}
	res := ""
	for i, j, cnt := 0, 0, 0; j < n; j++ {
		hash[s[j]]++
		if hash[s[j]] <= 0 {
			cnt++
		}
		if cnt == m {
			for hash[s[i]] > 0 {
				hash[s[i]]--
				i++
			}
			if res == "" || j-i+1 < len(res) {
				res = s[i : j+1]
			}
		}
	}
	return res
}

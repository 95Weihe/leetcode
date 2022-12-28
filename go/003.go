package main

// 双循环的基础上优化，遍历每个元素然后以每个元素往后遍历不重复字串。
//->滑动窗口 第二次遍历无需从头开始，在第一次的基础上即可 时间复杂度2n

func lengthOfLongestSubstring(s string) (res int) {
	table := make(map[byte]int)
	len, rk := len(s), -1
	res = 0
	for i := 0; i < len; i++ {
		if i != 0 {
			delete(table, s[i-1])
		}

		for rk < len-1 && table[s[rk+1]] == 0 {
			table[s[rk+1]]++
			rk++
		}

		res = max(res, rk-i+1)
	}

	return
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

package main
/**
非负整数数组，从第一个位置出发，数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
dfs 超出时间限制 我直接记忆化一手 阁下如何应对
从左到右遍历，每次求出最大值，遍历的时候看最最大值能否到达这里。
能遍历完就代表可以到达最后一个
*/
func canJump(nums []int) bool {
	idx := 0
	dir = make([]int, len(nums))
	return jump(nums[idx], idx, nums)
}
// 记忆化
var dir []int
func jump(step, idx int, nums []int) bool {
	if idx == len(nums) - 1 {
		return true
	}
	for i := 1; i <= step; i++ {
		if dir[idx+i] == 1 {
			continue
		}
		res := jump(nums[idx+i], idx+i, nums)
		if res {
			return true
		} else {
			dir[idx+i] = 1
		}
	}
	return false
}

func jumpCan(nums []int) bool {
	maxJump := 0
	for i, v := range nums {
		if i > maxJump {
			return false
		}
		maxJump = max(maxJump, i+v)
	}
	return true
}
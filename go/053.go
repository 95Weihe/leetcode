package main
/**
从整数数组中找出一个 具有最大和的连续子数组 返回其最大和
动态规划：f[i] 0-i的最大值
f[i-1] < 0 f[i] = n[i]
f[i-1] > 0 f[i] = f[i-1] + n[i]
f[0] = n[0]
*/
func maxSubArray(nums []int) int {
	var f = make([]int, len(nums))
	f[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		if f[i-1] > 0 {
			f[i] = f[i-1] + nums[i]
		} else {
			f[i] = nums[i]
		}
	}
	var m = -10001
	for _, v := range f {
		m = max(m,v)
	}
	return m
}
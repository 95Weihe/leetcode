package main

/**
爬楼梯
经典递归问题
每次你可以爬1或2个台阶。你有多少种不同的方法可以爬到楼顶呢

经典动态规划
f[n] = f[n-1] + f[n-2]
*/

// 递归
func _climbStairs(n int) int {
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	return _climbStairs(n-1) + _climbStairs(n-2)
}

// 动态规划
func climbStairs(n int) int {
	f := make([]int, n)
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	f[0] = 1
	f[1] = 2
	for i := 2; i < n; i++ {
		f[i] = f[i-1] + f[i-2]
	}
	return f[n-1]
}

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

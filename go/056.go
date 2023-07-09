package main

import (
	"sort"
)

/**
in:  intervals = [[1,3],[2,6],[8,10],[15,18]]
out: [[1,6],[8,10],[15,18]]
排序 按第一个字符升序排序，按照包含关系修改即可，遍历一遍intervals
*/

type array [][]int

func (a array) Len() int {
	return len(a)
}
func (a array) Less(i, j int) bool {
	return a[i][0] < a[j][0]
}
func (a array) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func merge(intervals [][]int) [][]int {
	res := make([][]int, 0)
	n := len(intervals)
	sort.Sort(array(intervals))
	res = append(res, intervals[0])
	for i := 1; i < n; i++ {
		idx := len(res) - 1
		if res[idx][1] >= intervals[i][0] {
			res[idx][1] = max(res[idx][1], intervals[i][1])
		} else {
			res = append(res, intervals[i])
		}
	}
	return res
}

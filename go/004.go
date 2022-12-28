package main

import "fmt"

func findMedianSortedArrays(nums1 []int, nums2 []int) (res float64) {
	m, n := len(nums1), len(nums2)
	len := m + n

	t := make([]int, len)
	i, j, k := 0, 0, 0
	for ; i < m || j < n; k++ {
		if j >= n || i < m && nums1[i] < nums2[j] {
			t[k] = nums1[i]
			i++
		} else {
			t[k] = nums2[j]
			j++
		}
	}
	//012345
	mid := len / 2
	if len%2 == 0 {
		res = (float64(t[mid]) + float64(t[mid-1])) / 2.0
	} else {
		res = float64(t[mid])
	}
	return
}

func main() {
	nums1 := []int{3}
	nums2 := []int{-2, -1}
	t := findMedianSortedArrays(nums1, nums2)
	fmt.Println(t)
}

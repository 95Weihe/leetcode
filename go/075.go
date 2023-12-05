package main

/**
颜色分类
红 白 蓝，使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
经典双指针问题
思路：双指针维护三个区间即可
重点在于如何利用双指针去维护
定义 0000 |l| 1111 |r| 2222 即两个边界线
循环不变式，维护指针的意义
l r 代表左右两个分界线 i 循环迭代标记
为了方便迭代 l=-1  r=len  max(i) = r-1
*/
func sortColors(nums []int) {
	l, r := -1, len(nums)
	for i := 0; i < r; {
		if nums[i] == 0 {
			l++
			swap(nums, l, i)
			i++
			continue
		}
		if nums[i] == 1 {
			i++
			continue
		}
		if nums[i] == 2 {
			r--
			swap(nums, r, i)
		}
	}
}

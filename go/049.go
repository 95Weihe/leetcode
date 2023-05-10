package main

import "sort"

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
	return len(s)
}

/**
思路：将每一个字符串排序（内部字母排序）,具有相同字符串肯定相等，然后用map存储即可。
*/
func groupAnagrams(strs []string) [][]string {
	record, res := map[string][]string{}, [][]string{}
	for _, str := range strs {

		sByte := []rune(str)
		sort.Sort(sortRunes(sByte))

		s := record[string(sByte)]
		s = append(s, str)
		record[string(sByte)] = s
	}
	for _, v := range record {
		res = append(res, v)
	}
	return res
}

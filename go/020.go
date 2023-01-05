package main

/**
括号匹配
思路：用栈，遇到左边部分进栈，遇到右边取栈顶元素检查是否匹配。最后检查栈是否为空即可
*/
func isValid(s string) bool {
	stack := make([]byte, 0)
	for i := 0; i < len(s); i++ {
		v := s[i]
		if (v == '(') || (v == '[') || (v == '{') {
			stack = append(stack, v)
		} else if ((v == ']') && len(stack) > 0 && stack[len(stack)-1] == '[') ||
			((v == ')') && len(stack) > 0 && stack[len(stack)-1] == '(') ||
			((v == '}') && len(stack) > 0 && stack[len(stack)-1] == '{') {
			stack = stack[:len(stack)-1]
		} else {
			return false
		}
	}
	return len(stack) == 0
}

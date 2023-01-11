class Solution {
    /**
     给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

     有效字符串需满足：

     左括号必须用相同类型的右括号闭合。
     左括号必须以正确的顺序闭合。
     每个右括号都有一个对应的相同类型的左括号

     */
    public boolean isValid(String s) {
        Deque<Character> deque = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char str = s.charAt(i);
            if (str == '(' || str == '[' || str == '{') {
                deque.push(str);
            } else {
                if(deque.size() == 0) return false;
                if (str == ')' && deque.pop() != '(') {
                    return false;
                } else if (str == ']' && deque.pop() != '[') {
                    return false;
                } else if (str == '}' && deque.pop() != '{') {
                    return false;
                }
            }
        }
        return deque.size() == 0;
    }
}

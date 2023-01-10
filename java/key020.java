public boolean isValid(String s) {
    /*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
    if(s.isEmpty())
        return true;
    Stack<Character> stack=new Stack<Character>();
    for(char c:s.toCharArray()){
        if(c=='(')
            stack.push(')');
        else if(c=='{')
            stack.push('}');
        else if(c=='[')
            stack.push(']');
        else if(stack.empty()||c!=stack.pop())
            return false;
        }
    if(stack.empty())
        return true;
    return false;
}
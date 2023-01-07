class Solution {
/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
    ArrayList  res = new ArrayList();
    int indexs;
    String [] letterMap = new String[]{
        " ",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz"//9
        };
    private void findCombination(String digits, int index, String s ){
        if( index == digits.length()){
            //保存s
           res.add (s);
            return ;
        }
        char c = digits.charAt(index);
        if( c - '0' > 1 && c - '9' <= 0 );
        String letters = letterMap[c - '0'];
        for (int i = 0;i < letters.length(); i++)
            findCombination( digits ,index+1,s + letters.charAt(i));
    }
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return res;
        findCombination(digits,0,"");
        return res;
    }
}
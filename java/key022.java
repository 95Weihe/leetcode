public class Solution {
    //数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

    // 返回结果集
    List<String> res = new ArrayList<>();

    // 括号个数
    int n;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        // 特殊情况
        if (n == 0) {
            return res;
        }

        // 深度遍历：构造一个树，左子树为向结果字符串中添加左括号(，右子树为向结果字符串中添加右括号)
        dfs("", 0, 0);
        return res;
    }
    /**
     * @param curStr 递归到当前层中，公共变量已经存放的括号排列组合的中间结果
     * @param left   左括号已经用了几个
     * @param right  右括号已经用了几个
     */
    private void dfs(String curStr, int left, int right) {
        // 终止条件：当左右括号都用完的时候，可以将中间结果加入最终结果集中
        if (left == n && right == n) {
            res.add(curStr);
            return;
        }
        // 剪枝：当已经使用的左括号的数量，已经比已经使用的右括号的数量少时
        // 说明curStr中的左括号数量少于右括号，那么必然不可能合法，因此剪枝
        if (left < right) {
            return;
        }
        // 当还剩余左括号时，将左括号加入中间变量中，代表向左子树递归
        if (left < n) {
            dfs(curStr + "(", left + 1, right);
        }
        // 当还剩余右括号时，将右括号加入中间变量中，代表向右子树递归
        if (right < n) {
            dfs(curStr + ")", left, right + 1);
        }
    }
}

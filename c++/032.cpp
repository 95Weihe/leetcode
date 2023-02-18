class Solution {
/*
[栈的思路](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/#:~:text=%E6%96%B9%E6%B3%95%E4%BA%8C%EF%BC%9A-,%E6%A0%88,%E7%9A%84%E5%85%83%E7%B4%A0%E3%80%82,-1%20/%2011)

[动态规划](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-si-lu-xiang-jie-c-by-zhanganan042/)
*/
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size, 0);

        int maxVal = 0;
        for(int i = 1; i < size; i++) { //每次判断一个s[i]即可
            //若s[i]=='(',只能与后面的配对
            if (s[i] == ')') {
                if (s[i - 1] == '(') { //与i-1配对
                    dp[i] = 2;
                    if (i - 2 >= 0) {
                        dp[i] = dp[i] + dp[i - 2]; //配对 [i-1,i]，长度要加上dp[i-2]
                    }
                } else if (dp[i - 1] > 0) { //跳过[i-dp[i-1],i-1]段
                    if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;  //长度每次加2
                        if ((i - dp[i - 1] - 2) >= 0) { 
                            //配对 [i-dp[i-1]-1,i], 长度要加上dp[i-dp[i-1]-1-1]
                            dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};

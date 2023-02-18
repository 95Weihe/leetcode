/*
[动态规划](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/comments/#:~:text=%E8%A7%84%E5%88%92%E6%9C%89%E6%89%80%E5%B8%AE%E5%8A%A9%E3%80%82-,%23%23%20%E6%80%9D%E8%B7%AF,-%E7%9B%B8%E5%AF%B9%E4%BA%8E%E5%8A%A8%E6%80%81)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[n - 1][3],max(dp[n - 1][1], dp[n - 1][2]));
    }
};
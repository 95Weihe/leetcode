class Solution {
/*
[动态规划，类似【63.不同路径】](https://leetcode.cn/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/#:~:text=%E4%B8%8B%E4%B8%80%E9%A2%98%E8%A7%A3-,%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84,-%E5%85%B3%E6%B3%A8%20TA)
*/
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int dp[m][n];
        for(int i=0; i<n; i++)
            dp[0][i] = i>0?grid[0][i]+dp[0][i-1]:grid[0][0];
        for(int i=1; i<m; i++)
            dp[i][0] = grid[i][0]+dp[i-1][0];
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
        return dp[m-1][n-1];
    }
};
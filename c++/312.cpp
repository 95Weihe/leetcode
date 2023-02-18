/*
[动态规划](https://blog.csdn.net/weixin_43314519/article/details/108132528)

[视频讲解](https://www.bilibili.com/video/BV1fY411x7pg/?p=14)
*/
class Solution {
public:
    /*
    动态规划：
    CSDN：https://blog.csdn.net/weixin_43314519/article/details/108132528
    视频讲解：https://www.bilibili.com/video/BV1fY411x7pg/?p=14
    */
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> points(n+2,1);
        vector<vector<int>> dp(n+2,vector(n+2,0));

        for(int i=0; i<n; i++)
            points[i+1] = nums[i];
        for(int i=n; i>=0; i--){
            for(int j=i+1; j<n+2; j++){
                for(int k=i+1; k<j; k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+points[j]*points[k]*points[i]);
                }
            }
        }
        return dp[0][n+1];
    }
};
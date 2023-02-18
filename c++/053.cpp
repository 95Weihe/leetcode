class Solution {
//动态规划：dp[i] = max(dp[i-1]+nums[i],nums[i]); 结果为 dp 最大值
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        return *max_element(dp,dp+n);
    }
};
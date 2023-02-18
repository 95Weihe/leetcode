class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), ans=1;
        //dp[i]：表示以第 i 个数为结尾的最长递增子序列的长度
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            //dp[i] = max{ 0, dp[j] } + 1, 0<j<i, nums[j]<nums[i]
            int max = 0;
            for(int j=0; j<i; j++)
                if(dp[j]>max && nums[j]<nums[i])
                    max = dp[j];
            dp[i] = max + 1;
            if(dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;  
    }
};
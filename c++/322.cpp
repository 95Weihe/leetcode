class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(), MAX=0x7fffffff;
        vector<int> dp(amount+1,MAX);
        dp[0]=0;
        for(int j=0; j<n; j++){
            for(int i=coins[j]; i<=amount; i++){
                dp[i] = min(dp[i]-1,dp[i-coins[j]])+1;
            }
        }
        return dp[amount]==MAX?-1:dp[amount];
    }
};
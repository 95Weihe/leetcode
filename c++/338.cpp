class Solution {
public:
    vector<int> countBits(int n) {
        int k=0;
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            if(i==(1<<k)){
                k++;
                dp[i] = 1;
            }else dp[i] = dp[i-(1<<(k-1))]+1;
        }
        return dp;
    }
};
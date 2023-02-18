class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1);
        dp[0] = 0;
        for(int i=2; i<=n; i++){
            int q = (int)sqrt(i);
            if(q*q!=i){
                for(int j=1; j*j<=i; j++){
                    int t = dp[j*j]+dp[i-j*j];
                    dp[i] = dp[i]==1?t:min(t,dp[i]);
                }
            }
        }
        return dp[n];
    }
};
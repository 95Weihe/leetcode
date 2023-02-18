class Solution {
public:
    int climbStairs(int n) {
        if(n<3){
            return n;
        }
        // unique_ptr<int[]> dp(new int[n+1]);

        // dp[1]=1;
        // dp[2]=2;
        // for(int i=3; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        int f1=1, f2=2;
        for(int i=3; i<=n; i++){
            int f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};
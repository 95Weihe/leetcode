class Solution {
/*
1. 若把向下看做“写0”，把向上看做“写1”，则问题即为：求m-1个0，n-1个1的全排列个数
2. 公式为：(m+n-2)! / ( (m-1)! * (n-1)! )
3. 难点在于：直接算阶乘必越界，故需要利用“/”来减小每一步的 r 和 i

公式中（m+n-2）> max(m-1,n-1)，故阶乘可抵消max

进阶：可在抵消掉最大值之后，从小到大同时乘除



动态规划：dp[i][j] = dp[i-1][j] + dp[i][j-1]
即：每一步的可从上一格或左一格走来，故每一格的路径数即为上一格的路径数 + 左一格的路径数
而初始化：即边界点均为1

*/
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int max,min;
        max = m>n?m:n;
        min = m>n?n:m;
        int r=1, Min[min];
        for(int i=2; i<min; i++)
            Min[i]=i;
        for(int i=m+n-2;i>=max; i--){
            int t=i;
            for(int j=2; j<min; j++){
                if(Min[j]>1&&t%Min[j]==0){
                    t /= Min[j];
                    Min[j] = 1;
                }
                if(Min[j]>1&&r%Min[j]==0){
                    r /= Min[j];
                    Min[j] = 1;
                }
            }
            r *= t;
        }
        for(int j=2; j<min; j++){
            if(Min[j]>1&&r%Min[j]==0){
                r /= Min[j];
                Min[j] = 1;
            }
        }
        return r;
    }
};
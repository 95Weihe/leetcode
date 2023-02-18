/*
动态规划：
dp[i][j]：以 m[i][j] 为右下角的最大正方形的面积
动态方程：dp[i][j] = 根号下( min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) +1 )^2
初始化：dp[i][0] = m[i][0], dp[0][i] = m[0][i]
结果：dp中的最大值
*/
class Solution {
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp;
        int res=0;
        int row = matrix.size(), col = matrix[0].size();
        dp.resize(row,vector<int>(col,0));
        for(int i=0; i<col; i++){
            if(matrix[0][i]=='1'){
                dp[0][i] = 1;
                res = 1;
            }
        }
        for(int i=0; i<row; i++){
            if(matrix[i][0]=='1'){
                dp[i][0] = 1;
                res = 1;
            }
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                }else{
                    int t =(int)sqrt((double)min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}));
                    dp[i][j] = (t+1)*(t+1);
                }
                res = max(dp[i][j],res);
            }
        }
        return res;
    }
};
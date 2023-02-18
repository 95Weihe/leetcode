class Solution {
/*
[动态规划](https://leetcode.cn/problems/edit-distance/comments/#:~:text=2021%2D08%2D05-,%23%23%20%E6%9C%AC%E9%A2%98%E6%80%9D%E8%B7%AF,-%E4%B8%8D%E5%B0%91%E5%90%8C%E5%AD%A6%E5%AF%B9)

dp[i][j] 表示以下标i-1为结尾（前i个字符）的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]

初始化：dp[i][0] ：以下标i-1为结尾的字符串word1，和空字符串word2，最近编辑距离为dp[i][0]。
那么dp[i][0]就应该是i，对word1里的元素全部做删除操作，即：dp[i][0] = i;
同理dp[0][j] = j;

增操作add：dp[i][j-1]+1;
删操作del：dp[i-1][j]+1;
改操作rep：dp[i-1][j-1]+1;

动态方程：
1. 若 word1[i-1]==word[j-1]，dp[i][j] = dp[i-1][j-1]
2. 否则，dp[i][j] = min( add, del, rep );

结果：
dp[word1.size()][word2.size()]
*/
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        int dp[n1+1][n2+1];
        for(int i=0; i<=n1; i++)
            dp[i][0] = i;
        for(int i=0; i<=n2; i++)
            dp[0][i] = i;
        //双循环可理解为建造 dp 的过程
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    //min 中有两个以上元素，即应形成列表
                    dp[i][j] = min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[n1][n2];
    }
};
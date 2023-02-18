class Solution {
public:
    bool isMatch(string s, string p) {
         int m = s.size();
        int n = p.size();
//求是否匹配
        auto matches = [&](int i, int j) {
        //Int i ；int j中的i、j是指索引

        //当i为1;j不为1的时候，返回false
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            //返回末尾的前一位;若ture;则
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                //p[j-2]匹配0个的时候，f[i][j]为f[i][j - 2]  s[i-1]、p[j-3]判断结果

                    f[i][j] |= f[i][j - 2];      //|= 使用的原因：存在true就返回true；全部false才false
                    if (matches(i, j - 1)) {      //当s[i-1]==p[j-2]满足时，可以丢掉s[i-1]继续判断；

                    //f[i][j] 为f[i - 1][j]的判断结果
                    //|=是按位或并赋值的意思。若有两个整型变量a和b，那么a|=b;就是a=a|b;的意思。
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {

                //s[i - 1] == p[j - 1]时;
                //f[i][j]为f[i - 1][j - 1]判断结果
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
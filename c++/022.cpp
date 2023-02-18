class Solution {
/*
[简单易懂的动态规划](https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/)
*/
public:
    vector<string> generateParenthesis(int n) {
         vector<string> res;
        string str;
        stack<string> s;
        stack<int> l, r;
        int L=1, R=0;
        char c1='(', c2=')';
        str+=c1;
        s.push(str);
        l.push(L);
        r.push(R);
        while(!s.empty()){
            str = s.top();
            L = l.top();
            R = r.top();
            s.pop();
            l.pop();
            r.pop();
            if((L==n)&&(R==n)){
                res.push_back(str);
                continue;
            }
            if(L < n ){
                str = str + c1;
                L++;
                s.push(str);
                l.push(L);
                r.push(R);
                str.erase(str.length()-1);
                L--;
            }
            if(R < n && L > R){
                str = str + c2;
                R++;
                s.push(str);
                r.push(R);
                l.push(L);
            }
        }
        return res;
    }
};
class Solution {
/*
动态规划方程：P(i,j)=P(i+1,j−1)∧(S[i]==S[j])
即：只有 s[i+1~j-1]是回文串，并且 s 的第 i 和 j 个字母相同时，s[i~j]才会是回文串。
初始状态，l=r 时，此时 dp[l][r]=true
*/
public:
    string longestPalindrome(string s) {
        if(s.empty()||s.size()==1) return s;
        int start,len=0;
        int l1,l2,r1,r2;
        for(int i=1; i<s.size(); i++){
            auto [l1,r1] = expandCenter(s,i,i);
            auto [l2,r2] = expandCenter(s,i-1,i);
            if(r1-l1+1>len){
                len = r1-l1+1;
                start = l1;
            }
            if(r2-l2+1>len){
                len = r2-l2+1;
                start = l2;
            }
        }
        return s.substr(start,len);
    }

    pair<int,int> expandCenter(string& s,int l,int r){
        int i=l,j=r;
        while(i>=0&&j<s.size()){
            if(s[i]!=s[j])
                break;
            i--,j++;
        }
        return {i+1,j-1};
    }
};
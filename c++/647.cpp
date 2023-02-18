class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0; i<s.length(); i++){
            int t1 = Palindrome(s,i,i);
            int t2 = Palindrome(s,i,i+1);
            res += (t1+1)/2 + (t2+1)/2;
        }
        return res;
    }

    int Palindrome(string s,int l,int r){
        while(l>=0&&r<s.size()&&s[l]==s[r]) l--,r++;
        return r-l-1;
    }
};
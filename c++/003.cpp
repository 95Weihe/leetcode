class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int tail=-1, ans=0;
        for(int i=0; i<s.length(); i++){
            if(i!=0){
                set.erase(s[i-1]);
            }
            while(tail+1<s.size()&&!set.count(s[tail+1])){
                set.insert(s[tail+1]);
                tail++;
            }
            ans = max(ans, tail-i+1);
        }
        return ans;
    }
};
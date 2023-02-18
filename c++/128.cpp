class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int res=0;
        for(auto x:nums){
            st.insert(x);
        }
        for(auto x:nums){
            // 这里的巧妙之处在于如果包含有x-1的数的话，就不需要比较，
            // 因为等到里面while循环的时候会去比较x+1的数。这样就能统计出连续递增。
            if(st.find(x-1)==st.end()){
                int t=x;
                while(st.find(t+1)!=st.end())
                    t++;
                res = max(res,t-x+1);
            }
        }
        return res;
    }
};
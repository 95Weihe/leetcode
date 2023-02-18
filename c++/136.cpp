class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=0, n=nums.size();
        //关键：异或运算
        for(int x:nums)
            k ^= x;
        return k;
    }
};
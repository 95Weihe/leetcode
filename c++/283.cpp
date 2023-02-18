class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0, q=0;
        while(1){
            while(p<nums.size()&&nums[p])
                p++;
            q=p+1;
            while(q<nums.size()&&!nums[q])
                q++;
            if(q<nums.size())
                swap(nums[p],nums[q]);
            else break;
        }
    }
};
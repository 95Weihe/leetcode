class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        //替换
        for(int i=0; i<nums.size(); i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i=1; i<=nums.size(); i++){
            if(nums[i-1]>0)
                res.push_back(i);
        }
        return res;
    }
};
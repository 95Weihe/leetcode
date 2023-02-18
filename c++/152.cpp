class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //关键：要维护每一次的最大值，最小值
        int _min=nums[0], _max=nums[0], ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            int mi = _min, ma = _max;
            _min = min({nums[i],nums[i]*mi,nums[i]*ma});
            _max = max({nums[i],nums[i]*mi,nums[i]*ma});
            ans = max(_max,ans);
        }
        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和
        vector<int> pre;
        //前缀和的统计，供查阅
        map<int,int> mp;
        int res=0;
        pre.push_back(0);
        for(int i=0; i<nums.size(); i++){
            int t = pre[i]+nums[i];
            //只要此前存在前缀和等于tar即可
            int tar = t-k;
            //说明包含nums[i]的前缀和是符合条件的
            if(!tar) res++;
            if(mp.find(tar)!=mp.end()){
                res += mp[tar];
            }
            pre.push_back(t);
            mp[t] += 1;
        }
        return res;
    }
};
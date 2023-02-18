class Solution {
/*
1. 结果集 res 初始化：添加一个空集
2. 向 res 的每一个元素加入 nums[i]，再添加至 res 中（原res不动，添加新元素）
*/
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(auto x:nums){
            int len=res.size();
            for(int i=0; i<len; i++){
                vector<int> t=res[i];
                t.push_back(x);
                res.push_back(t);
            }
        }
        return res;
    }
};
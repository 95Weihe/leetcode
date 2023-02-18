class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs({},nums);
        return res;
    }

    void dfs(vector<int> r,vector<int>& nums){
        if(r.size()==nums.size()){
            res.push_back(r);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(r.begin(),r.end(),nums[i])==r.end()){
                r.push_back(nums[i]);
                dfs(r,nums);
                r.pop_back();
            }
        }
    }
};
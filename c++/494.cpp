class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res=0;
        dfs(nums,target,0,0,res);
        return res;
    }
    //树的根节点为 下标-1
    //dfs的逻辑：k表示当前节点 下标，sum表示当前节点前（下标<k）的和
    void dfs(vector<int>& nums, int target, int k, int sum, int& res){
        if(k==nums.size()){
            if(sum==target)
                res++;
            return;
        }
        dfs(nums,target,k+1,sum+nums[k],res);
        dfs(nums,target,k+1,sum-nums[k],res);
    }
};
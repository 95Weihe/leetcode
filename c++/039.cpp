class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs({},candidates,target,0);
        return res;
    }
    void dfs(vector<int> r, vector<int>& c, int t, int k){  //因为调用函数时r的实参是临时的，所以不能引用&
        int sum = accumulate(r.begin(),r.end(),0);
        if(sum==t){
            res.push_back(r);
            return;
        }else if(sum>t)
                return;
        for(int i=k;i<c.size();i++){
            r.push_back(c[i]);
            dfs(r,c,t,i);
            r.pop_back();
        }
    }
};
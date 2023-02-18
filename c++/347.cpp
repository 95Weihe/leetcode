class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> mp;
        //计数
        for(auto x:nums){
            if(mp.find(x)!=mp.end()){
                mp[x]++;
            }else mp[x]=1;
        }
        vector<vector<int>> mv;
        for(auto it=mp.begin(); it!=mp.end(); it++)
            mv.push_back({it->first,it->second});
        findKthLargest(mv,k,res);
        return res;
    }
    
    void headAdjust(vector<vector<int>>& nums, int k, int n){
        vector<int> t = nums[k];
        for(int i=k*2+1; i<n; i=2*i+1){
            if(i+1<n&&nums[i+1][1]>nums[i][1]) i++;
            if(nums[i][1]>t[1]){
                nums[k] = nums[i];
                k = i;
            }else break;
        }
        nums[k] = t;
    }
    //堆排序找前k大元素
    void findKthLargest(vector<vector<int>>& nums, int k, vector<int>& res) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--)
            headAdjust(nums,i,n);
        for(int i=n-1; i>=0; i--){
            auto t = nums[0];
            nums[0] = nums[i];
            nums[i] = t;
            k--;
            if(k>=0)
                res.push_back(nums[i][0]);
            else return;
            headAdjust(nums,0,i);
        }
    }
};
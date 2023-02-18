class Solution {
/*
维护一个最远可达位置m，
在位置 i 可达的前提下（i<=m）：更新 m=max(m, i+[i])
若新的 m>=n-1 即为true
若某个 i 不可达则为 false
*/
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), i=0;
        while(i<n){
            if(nums[i]==0&&i!=n-1) return false;
            if(n-1<=i+nums[i]) return true;
            int k=i;
            for(int j=i+1; j<n&&j<i+nums[i]; j++){
                if(j+nums[j]>k+nums[k])
                    k=j;
            }
            i = k==i?i+nums[i]:k;
        }
        return false;
    }
};
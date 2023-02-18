class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0], cnt=1, n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==res){
                cnt++;
            }else if(cnt){
                cnt--;
            }else{
                res = nums[i];
                cnt++;
            }
        }
        return res;
    }
};
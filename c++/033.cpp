class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1,m;
        if(h<0)
            return -1;
        if(h==0)
            return nums[0]==target?0:-1;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target)
                return m;
            if(nums[0]<=nums[m]){
                if(target>=nums[0]&&target<nums[m]){
                    h = m-1;
                }else l = m+1;
            }else{
                if(target>nums[m]&&target<=nums[nums.size()-1]){
                    l = m+1;
                }else h = m-1;
            }
        }
        return -1;
    }

};
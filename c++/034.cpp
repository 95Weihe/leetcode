class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,m,r1=-2,r2=0;
        // if(h==0)
        //     return {-1,-1};
        while(l<=h){
            m = (l+h)/2;
            if(nums[m] == target){
                r1 = r2 = m;
                break;
            }else if(nums[m] < target){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        if(l<=h){
            while(r1>=0&&nums[r1]==target)
                --r1;
            while(r2<nums.size()&&nums[r2]==target)
                ++r2;
        }
        return {r1+1,r2-1};
    }
};
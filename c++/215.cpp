class Solution {
    void headAdjust(vector<int>& nums, int k, int n){
        int t = nums[k];
        for(int i=k*2+1; i<n; i=2*i+1){
            if(i+1<n&&nums[i+1]>nums[i]) i++;
            if(nums[i]>t){
                nums[k] = nums[i];
                k = i;
            }else break;
        }
        nums[k] = t;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--)
            headAdjust(nums,i,n);
        for(int i=n-1; i>=0; i--){
            int t = nums[0];
            nums[0] = nums[i];
            nums[i] = t;
            k--;
            if(k==0)
                return nums[i];
            headAdjust(nums,0,i);
        }
        return -1;
    }
};
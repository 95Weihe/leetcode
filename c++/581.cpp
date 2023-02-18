class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        思路：找到第一个逆序对和最后一个逆序对的位置，作为一个区间边界，
        然后，找该区间中的最小值min，最大值max
        然后，确定max在后面的位置，min在前面的位置
        */
        int n=nums.size();
        int l=n, r=-1;
        for(int i=1; i<n; i++)
            if(nums[i]<nums[i-1]){
                l = i-1;
                break;
            }
        for(int j=n-1; j>0; j--)
            if(nums[j]<nums[j-1]){
                r = j;
                break;
            }
        if(l>r) return 0;
        int min=nums[l], max=nums[l];
        for(int i=l+1; i<=r; i++){
            if(nums[i]<min){
                min = nums[i];
            }
            else if(nums[i]>max){
                    max = nums[i];
                }
        }
        int start=0,end=n-1;
        for(int i=l-1; i>=0; i--){
            if(nums[i]<=min){
                start = i+1;
                break;
            }
        }
        for(int i=r+1; i<n; i++){
            if(nums[i]>=max){
                end = i-1;
                break;
            }
        }
        return end-start+1;
    }

};
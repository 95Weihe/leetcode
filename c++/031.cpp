class Solution {
/*
1. 找到倒数第1个“顺序对”，记录下“顺序对”的第一个数 nums[k]；
2. [k+1,……,n-1]中找到大于 nums[k]的最小值，并与之交换
3. 对[k+1,n-1]进行插入排序（进阶：此区间定为逆序，即翻转即可）
*/
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k=-1,ai;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                k=i-1;
                break;
            }
        }
        if(k>=0){
            ai = k+1;
            for(int i=k+1; i<n; i++){
                if(nums[i]>nums[k]&&nums[i]<nums[ai])
                    ai=i;
            }
            swap(nums[ai],nums[k]);
        }
        for(int i=k+2,j; i<n; i++){
            if(nums[i]<nums[i-1]){
                int t = nums[i];
                for(j=i-1; j>=k+1&&nums[j]>t; j--)
                    nums[j+1] = nums[j];
                nums[j+1] = t; 
            }
        }
    }
};
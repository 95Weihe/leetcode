class Solution {
/*
[扫描一趟](https://leetcode.cn/problems/sort-colors/comments/#:~:text=2022%2D06%2D02-,%E5%8F%91%E7%8E%B0%E8%80%83%E7%A0%94%E7%AE%97%E9%A2%98%E7%9A%84%E6%97%B6%E5%80%99%E5%81%9A%E8%BF%87%E7%9A%84%E3%80%82,-1.%E8%AE%BE%E7%BD%AE%E4%B8%89)

设置三个指针：l, r, t;
保证：l 左边（不包括 l）全是0，r 右边（不包括 r）全是2
过程：t 为当前处理的元素
若 nums[t]==0，与 [l] 交换，此时 t++,l++，（交换后一定有 nums[l]==0）
若 nums[t]==1，跳过
若 nums[t]==2，与 [r] 交换，此时 r--, t不变。（因为交换后 nums[t] 是未知的）
*/
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=nums.size()-1, t=0;
        while(t<=r){
            if(nums[t]==0){
                swap(nums[l],nums[t]);
                l++;
                t++;
            }else if(nums[t]==2){
                swap(nums[r],nums[t]);
                r--;
            }else t++;
        }
    }
};
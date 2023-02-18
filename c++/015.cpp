class Solution {
/*
「双指针」：当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素下标的递增，第二个元素下标是递减的，那么就可以使用双指针的方法，将枚举的时间复杂度从 O(N^2) 减少至 O(N)
*/
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int k=0; k<n-2; k++){   //枚举至少保证最后有三个及以上的数
            if(nums[k]>0)      //因为已排好序，故后面的数的和必为正数
                break;
            if(k>0&&nums[k]==nums[k-1]) //过滤掉相同的数，避免结果重复
                continue;
            int i=k+1, j=n-1, t=-nums[k];
            while(i<j){     //双指针
                if(nums[i]+nums[j]==t){
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[i+1])  //过滤重复的数，避免结果重复
                        i++;
                    while(i<j&&nums[j]==nums[j-1])
                        j--;
                i++;j--;        
                }else if(nums[i]+nums[j]<t){
                    while(i<j&&nums[i]==nums[i+1])
                            i++;
                    i++;
                }else{
                    while(i<j&&nums[j]==nums[j-1])
                            j--;
                    j--;
                }                
            }
        }
        return res;
    }
};
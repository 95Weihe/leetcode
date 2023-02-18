class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2, n=nums.size();
        if(target*2!=sum)
            return false;
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        vector<int> dp(10001, 0);

        // 开始 01背包
        // 套路：dp[j] 表示： 容量为j的背包，所背的物品最大价值为dp[j]。
        // 本题中每一个元素的数值既是重量，也是价值，即：物品i的重量是nums[i]，其价值也是nums[i]。
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target) return true;
        return false;

        // //二进制法求子集
        // for(int i=1; i< 1<<n; i++){
        //     int t=0;
        //     for(int k=0; k<n; k++){
        //         //i的第k位是否为1
        //         if(i & 1<<k){
        //             t += nums[k];
        //         }
        //     }
        //     if(t == tar){
        //         return true;
        //     }
        // }
        // return false;
    }
};
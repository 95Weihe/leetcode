/*
我的思路（动态规划）：
1. dp[i][2]：[0] 表示不取 [i] 元素，[1] 表示取 [i] 元素
2. 状态方程：dp[i][0] = max( dp[0...i-1][1] )；dp[i][1] = max( dp[0...i-2][1] )+[i];

改进：状态转移中，只与 [0...i-1] 和 [0...i-2] 中的最大值有关，故用变量 _ max1 记录 [0...i-1] 中的max，_ max2 记录 [0...i-2] 中的 max
故： t = _max1;
         _max1 = max(_max1, _max2+nums[i]);
         _max2 = max(t,_max2);

初始化：int _max1=nums[0], _max2=0；
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        unique_ptr<int[]> dp(new int[nums.size()+1]);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        }
        return dp[nums.size()];
    }
};
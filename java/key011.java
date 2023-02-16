class Solution {
    public int maxArea(int[] height) {
        /*
        *给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i])
        * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
        * 返回容器可以储存的最大水量。
        * 说明：你不能倾斜容器。
        * */
        /*
        * 思路：最大盛水量 = 量数组之间的距离 * 容器高度
        * 容器高度由最短的一侧高度决定：由此，想要得多的水量就要移动最低的高度
        * 采用双指针，分别放在两侧，移动较小的一段，每移动一次计算水量，取最大值，知道两指针相遇
        * */
        int i = 0;
        int j = height.length - 1;
        int ans = 0;
        while(i < j) {
            ans = height[i] < height[j] ?
                    Math.max(ans, (j - i) * height[i++]):
                    Math.max(ans, (j - i) * height[j--]);
        }
        return ans;
    }
}

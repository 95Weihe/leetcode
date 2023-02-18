class Solution {
/*
思路类似于[接雨水. 动态规划](https://leetcode.cn/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/#:~:text=%E7%9A%84%E8%AE%A1%E7%AE%97%E5%A6%82%E4%B8%8B%EF%BC%9A-,%E5%BD%93,%E3%80%82,-%E5%9B%A0%E6%AD%A4%E5%8F%AF%E4%BB%A5%E6%AD%A3%E5%90%91)


关键：对于[i] ，应找到左右两侧最近的、且高度小于 [i] 的柱子

单调栈：
栈中存放了  j  值。从栈底到栈顶，j 的值严格单调递增，同时对应的高度值也严格单调递增；

当我们枚举到第 i 根柱子时，我们从栈顶不断地移除height[j]≥height[i] 的 j 值。在移除完毕后，栈顶的 j 值就一定满足height[j]<height[i]，**此时 j 就是 i 左侧且最近的小于其高度的柱子**。
*（若 i 从n向左枚举，则可得到右侧的柱子）*
这里会有一种特殊情况。如果我们移除了栈中所有的 j 值，那就说明 i 左侧所有柱子的高度都大于 height[i]，那么我们可以认为 
i 左侧且最近的小于其高度的柱子在位置 j=−1，它是一根「虚拟」的、高度无限低的柱子。这样的定义不会对我们的答案产生任何的影响，我们也称这根「虚拟」的柱子为「哨兵」。

再将 i 放入栈顶。
*/
public:
    int largestRectangleArea(vector<int>& heights) {
      int n=heights.size(), res=0;
      vector<int> l(n),r(n);

      stack<int> st;
      for(int i=0; i<n; i++){
        while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
        l[i] = st.empty()?-1:st.top();
        st.push(i);
      }
      st = stack<int>();
      for(int i=n-1; i>=0; i--){
        while(!st.empty()&&heights[st.top()]>=heights[i]) st.pop();
        r[i] = st.empty()?n:st.top();
        st.push(i);
      }
      for(int i=0; i<n; i++)
        res = max(res,heights[i]*(r[i]-l[i]-1));
      return res;
    }
};
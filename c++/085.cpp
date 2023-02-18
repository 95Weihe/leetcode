class Solution {
/*
[参考84.柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/?favorite=2cktkvj)
* 把每一行看做柱状图的底，高为当前底以上的连续个1，每行调用一次largestRectangleArea(vector<int> heights)，取最大者即可
*/
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> heights(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]!='0'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }
            res = max(res,largestRectangleArea(heights));
        }
        return res;
    }

    int largestRectangleArea(vector<int> heights) {
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
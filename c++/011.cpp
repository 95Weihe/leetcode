class Solution {
/*
若向内 移动短板 ，水槽的短板 min(h[i], h[j]) 可能变大，因此下个水槽的面积 可能增大 。
若向内 移动长板 ，水槽的短板 min(h[i], h[j])不变或变小，因此下个水槽的面积 一定变小 。
因此，初始化双指针分列水槽左右两端，循环每轮将短板向内移动一格，并更新面积最大值，直到两指针相遇时跳出；即可获得最大面积。
*/
public:
    int maxArea(vector<int>& height) {
        int res=0;
        for(int i=0, j=height.size()-1; i<j;){
            res = max(res,(j-i)*min(height[i],height[j]));
            height[i]>height[j]?j--:i++;
        }
        return res;
    }
};
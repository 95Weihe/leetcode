class Solution {
/*
我的思路：
1. 以矩阵对角线为对称轴，交换对称位置的值
2. 以矩阵竖对称轴为轴，交换对称位置的值
*/
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0; i<n; i++)
            for(int j=0,k=n-1;j<k;j++,k--)
                swap(matrix[i][j],matrix[i][k]);
    }
};
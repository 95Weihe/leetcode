class Solution {
    int t;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        t=target;
        return find(matrix,0,0,m-1,n-1);
    }
    bool find(vector<vector<int>>& ma, int l1, int l2, int r1, int r2){
        if(l1>r1||l2>r2||ma[l1][l2]>t||ma[r1][r2]<t) return false;
        int m1=(l1+r1)>>1, m2=(l2+r2)>>1;
        //关键，分割时舍弃掉中点
        if(ma[m1][m2]==t) return true;
        else if(ma[m1][m2]<t){
            return find(ma,l1,m2+1,m1,r2)||find(ma,m1+1,l2,r1,r2);
        }else{
            return find(ma,l1,l2,m1-1,r2)||find(ma,m1,l2,r1,m2-1);
        }
    }
};
class Solution {
/*
我的思路：
1. 找到两端较大者（即增大趋势的最大者）
2. 左端找最近的较大者，计算区间的“雨水”
3. 右端找最近的较大者，计算区间的“雨水”
4. 注意临界值：当两端指针相遇时，计算某一端的情况即可
*/
public:
    int trap(vector<int>& height) {
        int f=0,n=height.size(),p,q;
        int k=0;
        while(k<n&&height[k]>=f){
            f=height[k++];
        }
        p=k-1;
        k=n-1;
        f=-1;
        while(k>=p&&height[k]>=f){
            f=height[k--];
        }
        q=k+1;

        int res=0,ls,rs,i,j;
        while(p<q){
            i=p+1;
            ls=0;
            while(i<=q&&height[i]<height[p]){
                ls += height[i++];
            }
            //只有当找到了 >=[p] 的且非q柱子，或者是q且满足柱子[q]>=[p]时计算
            if(i<q||(i==q&&height[q]>=height[p])){
                ls = min(height[i],height[p])*(i-p-1)-ls;
                p=i;
                res += ls;
            }

            j=q-1;
            rs=0;
            while(p<=j&&height[j]<height[q])
                rs += height[j--];
            //在找到了 >=[q] 且非p的柱子， 或者是p且满足柱子[p]>=[q]时计算
            if(j>p||(j==p&&height[q]<=height[p])){
                rs = min(height[j],height[q])*(q-j-1)-rs;
                q=j;
                res += rs;
            }
            
        }
        return res;
    }
};
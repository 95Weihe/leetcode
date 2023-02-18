class Solution {
/*
1. 该题实际上即是：求 n 个节点的不同形态的二叉树种类
2. 公式：C(2n,n)/(n+1) = (2n)!/( (n+1)! n!)
3. 将公式变换为：[ (n* (n+1)……* 2n）/ (1* 2*……* (n+1) ] / n
要点：分子，分母从最小处开始同步递增，同时进行乘除，即可保证每次结果均可整除（因为是同步递增，所以分子连乘的结果必是分母的倍数）
*/
public:
    int numTrees(int n) {
        if(n==1) return 1;
        // return numTrees(n-1)/(n+1)*(4*n-2);
        long long res=1LL;
        for(int i=1,j=n; i<=n+1; i++,j++){
            res = res * j/i;
        }
        res/=n; 
        return (int)res;
    }
};
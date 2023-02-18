class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, res=0;
        for(int i=0; i<31; i++){
            if(z&(1<<i))
                res++;
        }
        return res;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //看成找环的入口
        int f=0, s=0;
        do{
            f=nums[nums[f]];
            s=nums[s];
        }while(f!=s);
        int p=0,q=s;
        while(p!=q){
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};
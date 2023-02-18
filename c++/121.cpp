class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], proift=0;
        for(auto x:prices){
            if(x>min){
                proift = max(proift,x-min);
            }else{
                min = x;
            }
        }
        return proift;
    }
};
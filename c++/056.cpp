class Solution {
/*
我的思路：
1. 用res存储 [0,i-1] 的合并结果
2. 对于 intervals[i]，扫描res，若能与 intervals[i]合并：立即合并，且将其从res中删除


进阶：
若将区间按左端点排序，则能够合并的区间一定是连续的
用 res 存储合并结果，则对于 intervals[i] ，只需考虑是否能与 res 的尾元素是否能合并，且只可能与尾元素进行合并
合并：只需更改 res尾元素的右端点
*/
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
        vector<vector<int>> res={intervals[0]};
        for(int k=1;k<intervals.size();k++){
            vector<int> t=intervals[k];
            for(vector<vector<int>>::iterator it=res.begin();it!=res.end();){
                if(t[1]<(*it)[0]||t[0]>(*it)[1]){
                    it++;
                }else{
                    t[0] = min(t[0],(*it)[0]);
                    t[1] = max(t[1],(*it)[1]);
                    it = res.erase(it);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};
/*
[单调队列](https://leetcode.cn/problems/sliding-window-maximum/comments/#:~:text=%E8%AE%BE%E8%AE%A1%E5%8D%95%E8%B0%83%E9%98%9F%E5%88%97,%E7%AA%97%E5%8F%A3%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC%E3%80%82)
用双端队列结构维护一个单调递减的队列
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i=0; i<nums.size(); i++){
            if(i<k){
                while(!dq.empty()&&dq.back()<nums[i])
                    dq.pop_back();
                dq.push_back(nums[i]);
            }else{
                res.push_back(dq.front());
                if(nums[i-k]==dq.front())
                    dq.pop_front();
                while(!dq.empty()&&dq.back()<nums[i])
                    dq.pop_back();
                dq.push_back(nums[i]);
                // res.push_back(dq.front());
            }
        }
        res.push_back(dq.front());
        return res;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        思路：单调栈：反向遍历数组，构造单调递减的栈（栈顶最小）
        */
        vector<int> res;
        stack<int> st;
        int n=temperatures.size();
        res.push_back(0);
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.empty()){
                res.push_back(0);
            }else{
                res.push_back(st.top()-i);
            }
            st.push(i);
        }
        return vector(res.rbegin(),res.rend());
    }
};
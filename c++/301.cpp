/*
[BFS](https://leetcode.cn/problems/remove-invalid-parentheses/comments/#:~:text=%E5%88%A9%E7%94%A8BFS%E7%90%86%E8%A7%A3%E8%B5%B7%E6%9D%A5%E8%A6%81%E8%BF%9C%E8%BF%9C%E6%AF%94DFS%E8%A6%81%E7%AE%80%E5%8D%95%E7%9A%84%E5%A4%9A%EF%BC%8C%E5%9B%A0%E4%B8%BA%E8%BF%99%E9%81%93%E9%A2%98%E8%AF%B4%E7%9A%84%E6%98%AF%E5%88%A0%E9%99%A4%E6%9C%80%E5%B0%91%E7%9A%84%E6%8B%AC%E5%8F%B7%EF%BC%81%EF%BC%81%EF%BC%8C%E5%A6%82%E6%9E%9C%E6%88%91%E4%BB%AC%E6%AF%8F%E6%AC%A1%E5%8F%AA%E5%88%A0%E9%99%A4%E4%B8%80%E4%B8%AA%E6%8B%AC%E5%8F%B7%EF%BC%8C%E7%84%B6%E5%90%8E%E8%A7%82%E5%AF%9F%E8%A2%AB%E5%88%A0%E9%99%A4%E4%B8%80%E4%B8%AA%E6%8B%AC%E5%8F%B7%E5%90%8E%E6%98%AF%E5%90%A6%E5%90%88%E6%B3%95%EF%BC%8C%E5%A6%82%E6%9E%9C%E5%B7%B2%E7%BB%8F%E5%90%88%E6%B3%95%E4%BA%86%EF%BC%8C%E6%88%91%E4%BB%AC%E5%B0%B1%E4%B8%8D%E7%94%A8%E7%BB%A7%E7%BB%AD%E5%88%A0%E9%99%A4%E4%BA%86%E5%95%8A%E3%80%82%E5%9B%A0%E6%AD%A4%E6%88%91%E4%BB%AC%E5%B9%B6%E4%B8%8D%E9%9C%80%E8%A6%81%E5%B0%86%E9%81%8D%E5%8E%86%E8%BF%9B%E8%A1%8C%E5%88%B0%E5%BA%95%EF%BC%8C%E8%80%8C%E6%98%AF%E5%B1%82%E5%B1%82%E6%B7%B1%E5%85%A5%EF%BC%8C%E4%B8%80%E6%97%A6%E8%BE%BE%E5%88%B0%E9%9C%80%E6%B1%82%EF%BC%8C%E5%B0%B1%E4%B8%8D%E5%86%8D%E6%B7%B1%E5%85%A5%E4%BA%86%E3%80%82)
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        //保证level及next内的元素不重复
        unordered_set<string> level,next;
        vector<string> res;
        level.insert(s);
        //广度优先搜索，下一层next是 level中的元素删除'('或')'得到
        while(1){
            for(auto x:level)
                if(isValid(x)){
                    //将合法括号加入结果集
                    res.push_back(x);
                }
            //由于BFS每一次搜索是所有情况删除一个字符得到另外的所有情况，若某一次删除得到了有效括号，则此次即是最少删除数
            if(!res.empty())
                break;
            // next.clear();
            for(auto s:level){
                for(int i=0; i<s.length(); i++){
                    //忽略字母
                    if(s[i]=='('||s[i]==')')
                        next.insert(s.substr(0,i)+s.substr(i+1));
                }
            }
            level = move(next);
        }
        return res;
    }

    //判定s是否为合法括号
    bool isValid(string s){
        int cnt=0;
        for(auto c:s){
            if(c=='(') cnt++;
            else if(c==')') cnt--;
            if(cnt<0) return false;
        }
        return cnt==0;
    }
};
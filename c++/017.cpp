class Solution {
/*
可用队列+BFS
将每次整体字符串入队
*/
    map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s;
        dfs(s,"",0,digits);
        return s;
    }
    void dfs(vector<string>& s, string t, int i, string d){
        if(i==d.size()){
            if(t!="")
                s.push_back(t);
            return;
        }
        for(int k=0;k<mp[d[i]].size();k++){
            t += mp[d[i]][k];
            dfs(s,t,i+1,d);
            t.pop_back();
        }
    }
};
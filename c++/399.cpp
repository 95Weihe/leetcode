class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_set<string> ver;
        map<string,vector<pair<string,double>>> G;
        map<string,bool> visit;
        //建图
        for(int i=0; i<equations.size(); i++){
            string s0=equations[i][0], s1=equations[i][1];
            G[s0].push_back({s1,values[i]});
            G[s1].push_back({s0,1/values[i]});
            ver.insert(s0);
            ver.insert(s1);
        }
        for(auto x:ver){
            visit[x] = false;
        }
        //深度优先搜索计算值
        for(auto x:queries){
            if(ver.find(x[0])!=ver.end()&&ver.find(x[1])!=ver.end()){
                res.push_back(dfs(G,x[0],x[1],visit));
                visit[x[0]] = 0;
            }else res.push_back(-1.0);   
        }
        return res;
    }
    double dfs(map<string,vector<pair<string,double>>>& G, string start, string end, map<string,bool>& visit){
        if(start==end){ //找到了目标end
            return 1;
        }
        visit[start] = 1;
        for(int i=0; i<G[start].size(); i++){
            auto p = G[start][i];
            if(!visit[p.first]){
                double t = dfs(G,p.first,end,visit);
                //回溯
                visit[p.first] = 0;
                //说明此次搜索中找到了目标end，即返回结果（要计算本节点）
                if(t>0)
                    return t*p.second;
            }
        }
        //此次搜索中没有目标end
        return -1;
    }
};
//深度优先搜索判断图是否有环
class Solution {
    vector<vector<int>> G;
    //标记矩阵,0为当前结点未访问,-1为访问过且后边节点正在被访问,1表示当前结点及后边的结点都被访问过。
    vector<int> visit;
    int n;
    bool res=true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        G.resize(numCourses,vector<int>(numCourses,0));
        visit.resize(numCourses,0);
        n = numCourses;
        for(auto x:prerequisites){
            G[x[0]][x[1]] = 1;
        }
        for(int i=0; i<numCourses; i++){
            if(visit[i]==0&&res){
                dfs(i);
            }
        }
        return res;
    }

    void dfs(int k){
        visit[k] = -1;
        for(int i=0; i<n; i++){
            if(G[k][i]!=0){
                if(visit[i]==-1){
                    res = false;
                    return;
                }else if(visit[i]==0){
                    dfs(i);
                }
            }
        }
        visit[k] = 1;
    }
};
class Solution {
    vector<vector<bool>> visit;
    int res,row,col;
public:
    int numIslands(vector<vector<char>>& grid) {
        row=grid.size(), col=grid[0].size();
        visit.resize(row,vector<bool>(col,false));
        res = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visit[i][j]&&grid[i][j]=='1'){
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int k, int l){
        visit[k][l]=true;
        int a[4] = {k-1,k+1,l-1,l+1};
        for(int i=0; i<4; i++){
            if(i<2){
                if(a[i]>=0&&a[i]<row&&grid[a[i]][l]=='1'&&!visit[a[i]][l]){
                    dfs(grid,a[i],l);
                }
            }else{
                if(a[i]>=0&&a[i]<col&&grid[k][a[i]]=='1'&&!visit[k][a[i]]){
                    dfs(grid,k,a[i]);
                }
            }
        }
    }
};
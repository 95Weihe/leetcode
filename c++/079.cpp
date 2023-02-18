class Solution {
    bool** visit;
    vector<vector<char>> bd;
    string w;
    int m,n;
    bool res=false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->bd.assign(board.begin(),board.end());
        this->w = word;
        m=board.size(), n=board[0].size();
        visit = new bool*[m];
        for(int i=0; i<m; i++){
            visit[i] = new bool[n];
            for(int j=0; j<n; j++)
                visit[i][j]=0;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!res&&board[i][j]==word[0]){
                    dfs(i,j,1);
                    visit[i][j]=0;
                }
            }
        }
        for(int i=0; i<m; i++)
            delete[] visit[i];
        delete[] visit;
        return res;
    }
    void dfs(int a, int b, int k){
        if(k>=w.length()||res){
            res = true;
            return;
        }
        visit[a][b]=1;
        int ar[4]={a-1,a+1,b-1,b+1};
        for(int i=0; i<4; i++){
            if(i<2){
                if(ar[i]>=0&&ar[i]<m&&!visit[ar[i]][b]&&bd[ar[i]][b]==w[k]){
                    dfs(ar[i],b,k+1);
                    visit[ar[i]][b]=0;
                }
            }else{
                if(ar[i]>=0&&ar[i]<n&&!visit[a][ar[i]]&&bd[a][ar[i]]==w[k]){
                    dfs(a,ar[i],k+1);
                    visit[a][ar[i]]=0;
                }
            }
        }
    }
};
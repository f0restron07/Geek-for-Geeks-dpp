class Solution {
  public:
    int n,m,best;
    void dfs(vector<vector<int>>& mat,vector<vector<char>>& vis,int i,int j,int xd,int yd,int len){
        if(i==xd&&j==yd){
            best=max(best,len);
            return;
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b]&&mat[a][b]==1){
                dfs(mat,vis,a,b,xd,yd,len+1);
            }
        }
        vis[i][j]=0;
    }
    int longestPath(vector<vector<int>>& mat,int xs,int ys,int xd,int yd){
        n=mat.size();
        m=mat[0].size();
        best=-1;
        if(mat[xs][ys]==0||mat[xd][yd]==0){
            return -1;
        }
        vector<vector<char>> vis(n,vector<char>(m,0));
        dfs(mat,vis,xs,ys,xd,yd,0);
        return best;
    }
};
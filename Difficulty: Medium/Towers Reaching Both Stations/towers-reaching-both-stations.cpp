class Solution {
  public:
    int n,m;
    void dfs(vector<vector<int>>& mat,vector<vector<char>>& vis,int i,int j){
        vis[i][j]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            if(a>=0&&a<n&&b>=0&&b<m&&!vis[a][b]&&mat[a][b]>=mat[i][j]){
                dfs(mat,vis,a,b);
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat){
        n=mat.size();
        m=mat[0].size();
        vector<vector<char>> p(n,vector<char>(m,0));
        vector<vector<char>> q(n,vector<char>(m,0));
        for(int j=0;j<m;j++){
            if(!p[0][j]){
                dfs(mat,p,0,j);
            }
            if(!q[n-1][j]){
                dfs(mat,q,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            if(!p[i][0]){
                dfs(mat,p,i,0);
            }
            if(!q[i][m-1]){
                dfs(mat,q,i,m-1);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]&&q[i][j]){
                    c++;
                }
            }
        }
        return c;
    }
};
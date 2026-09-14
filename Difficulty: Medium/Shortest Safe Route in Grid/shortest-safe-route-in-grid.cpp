class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> safe(n,vector<int>(m,1));
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    safe[i][j]=0;
                    for(int k=0;k<4;k++){
                        int a=i+dx[k];
                        int b=j+dy[k];
                        if(a>=0&&a<n&&b>=0&&b<m){
                            safe[a][b]=0;
                        }
                    }
                }
            }
        }
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(safe[i][0]){
                dist[i][0]=1;
                q.push({i,0});
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            if(j==m-1){
                return dist[i][j];
            }
            for(int k=0;k<4;k++){
                int a=i+dx[k];
                int b=j+dy[k];
                if(a>=0&&a<n&&b>=0&&b<m&&safe[a][b]&&dist[a][b]==-1){
                    dist[a][b]=dist[i][j]+1;
                    q.push({a,b});
                }
            }
        }
        return -1;
    }
};
class Solution {
  public:
    vector<int> findWays(vector<vector<int>>& grid){
        const long long M=1000000007;
        int n=grid.size();
        vector<vector<long long>> paths(n,vector<long long>(n,0));
        vector<vector<long long>> best(n,vector<long long>(n,-1));
        paths[0][0]=1;
        best[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(paths[i][j]==0){
                    continue;
                }
                int v=grid[i][j];
                if(v==1||v==3){
                    if(j+1<n){
                        paths[i][j+1]=(paths[i][j+1]+paths[i][j])%M;
                        best[i][j+1]=max(best[i][j+1],best[i][j]+grid[i][j+1]);
                    }
                }
                if(v==2||v==3){
                    if(i+1<n){
                        paths[i+1][j]=(paths[i+1][j]+paths[i][j])%M;
                        best[i+1][j]=max(best[i+1][j],best[i][j]+grid[i+1][j]);
                    }
                }
            }
        }
        long long p=paths[n-1][n-1];
        long long b=(p==0)?0:best[n-1][n-1];
        return {(int)p,(int)b};
    }
};
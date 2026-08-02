class Solution {
  public:
    int count(int n, int m){
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        for(int v=1;v<=m;v++){
            dp[1][v]=1;
        }
        for(int i=2;i<=n;i++){
            for(int v=1;v<=m;v++){
                for(int u=1;u<=m;u++){
                    if(u%v==0||v%u==0){
                        dp[i][v]+=dp[i-1][u];
                    }
                }
            }
        }
        long long ans=0;
        for(int v=1;v<=m;v++){
            ans+=dp[n][v];
        }
        return (int)ans;
    }
};
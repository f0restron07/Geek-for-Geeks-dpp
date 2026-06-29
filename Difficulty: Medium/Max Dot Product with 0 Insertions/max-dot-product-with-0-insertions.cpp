class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        const long long NEG=-1e18;
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,NEG));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m&&j<=i;j++){
                long long skip=dp[i-1][j];
                long long take=dp[i-1][j-1]+(long long)a[i-1]*b[j-1];
                dp[i][j]=max(skip,take);
            }
        }
        return (int)dp[n][m];
    }
};
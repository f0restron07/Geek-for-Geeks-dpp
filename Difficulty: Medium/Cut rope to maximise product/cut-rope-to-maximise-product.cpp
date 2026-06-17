class Solution {
  public:
    int maxProduct(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                int a=max(j,dp[j]);
                int b=max(i-j,dp[i-j]);
                dp[i]=max(dp[i],a*b);
            }
        }
        return dp[n];
    }
};
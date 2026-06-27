class Solution {
  public:
    int countWays(int n, int m) {
        const int M=1000000007;
        vector<long long> f(n+1,0);
        for(int i=0;i<m&&i<=n;i++){
            f[i]=1;
        }
        for(int i=m;i<=n;i++){
            f[i]=(f[i-1]+f[i-m])%M;
        }
        return (int)f[n];
    }
};
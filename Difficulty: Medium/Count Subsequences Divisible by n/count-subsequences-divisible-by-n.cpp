class Solution {
  public:
    int countSubsequences(string& s, int n){
        const long long M=1000000007;
        vector<long long> dp(n,0);
        for(char ch:s){
            int d=ch-'0';
            vector<long long> nd(n,0);
            for(int r=0;r<n;r++){
                if(dp[r]==0){
                    continue;
                }
                int nr=(r*10+d)%n;
                nd[nr]=(nd[nr]+dp[r])%M;
            }
            nd[d%n]=(nd[d%n]+1)%M;
            for(int r=0;r<n;r++){
                nd[r]=(nd[r]+dp[r])%M;
            }
            dp=nd;
        }
        return (int)dp[0];
    }
};
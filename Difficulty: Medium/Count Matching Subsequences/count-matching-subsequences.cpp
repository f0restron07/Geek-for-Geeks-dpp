class Solution {
  public:
    int countWays(string &s1, string &s2){
        const int M=1000000007;
        int a=s1.size();
        int b=s2.size();
        vector<long long> dp(b+1,0);
        dp[0]=1;
        for(int i=0;i<a;i++){
            for(int j=b;j>=1;j--){
                if(s1[i]==s2[j-1]){
                    dp[j]=(dp[j]+dp[j-1])%M;
                }
            }
        }
        return (int)dp[b];
    }
};
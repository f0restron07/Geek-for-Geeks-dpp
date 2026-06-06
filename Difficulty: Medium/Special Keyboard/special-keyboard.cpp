class Solution {
  public:
    int optimalKeys(int n) {
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;                 // just press 'A'
            for (int b = 1; b <= i - 3; b++)       // Ctrl+A, Ctrl+C, then pastes
                dp[i] = max(dp[i], dp[b] * (i - b - 1));
        }
        return (int)dp[n];
    }
};
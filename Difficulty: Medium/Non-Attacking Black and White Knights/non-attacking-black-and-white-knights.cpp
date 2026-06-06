class Solution {
  public:
    int numOfWays(int n, int m) {
        long long total = (long long)n * m;
        long long ways = total * (total - 1); 
        
        long long a = (n >= 2 && m >= 3) ? (long long)(n - 1) * (m - 2) : 0;
        long long b = (n >= 3 && m >= 2) ? (long long)(n - 2) * (m - 1) : 0;

        long long attacking = 4LL * (a + b);     // ordered attacking pairs

        return (int)(ways - attacking);
    }
};
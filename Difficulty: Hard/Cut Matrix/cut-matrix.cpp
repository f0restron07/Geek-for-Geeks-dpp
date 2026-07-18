class Solution {
  public:
    int findWays(vector<vector<int>>& matrix, int k) {
        const long long MOD=1000000007;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> a(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i+1][j+1]=a[i][j+1]+a[i+1][j]-a[i][j]+matrix[i][j];
            }
        }
        vector<vector<int>> b(n+1,vector<int>(m+1,n));
        for(int c=0;c<m;c++){
            b[n][c]=n;
            for(int r=n-1;r>=0;r--){
                b[r][c]=(a[r+1][m]-a[r][m]-a[r+1][c]+a[r][c]>0)?r:b[r+1][c];
            }
        }
        vector<vector<int>> d(n+1,vector<int>(m+1,m));
        for(int r=0;r<n;r++){
            d[r][m]=m;
            for(int c=m-1;c>=0;c--){
                d[r][c]=(a[n][c+1]-a[r][c+1]-a[n][c]+a[r][c]>0)?c:d[r][c+1];
            }
        }
        vector<vector<long long>> e(n+2,vector<long long>(m+2,0));
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                int s=a[n][m]-a[r][m]-a[n][c]+a[r][c];
                e[r][c]=s>0?1:0;
            }
        }
        for(int j=2;j<=k;j++){
            vector<vector<long long>> f(n+2,vector<long long>(m+2,0));
            for(int c=0;c<m;c++){
                for(int r=n-1;r>=0;r--){
                    f[r][c]=(f[r+1][c]+e[r][c])%MOD;
                }
            }
            vector<vector<long long>> g(n+2,vector<long long>(m+2,0));
            for(int r=0;r<n;r++){
                for(int c=m-1;c>=0;c--){
                    g[r][c]=(g[r][c+1]+e[r][c])%MOD;
                }
            }
            vector<vector<long long>> h(n+2,vector<long long>(m+2,0));
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    long long o=0;
                    int p=b[r][c];
                    if(p<n){
                        int q=p+1;
                        if(q<n){
                            o=(o+f[q][c])%MOD;
                        }
                    }
                    int s=d[r][c];
                    if(s<m){
                        int t=s+1;
                        if(t<m){
                            o=(o+g[r][t])%MOD;
                        }
                    }
                    h[r][c]=o;
                }
            }
            e=h;
        }
        return (int)e[0][0];
    }
};
class Solution {
    public int countSquare(int[][] mat, int x) {
        int n=mat.length,m=mat[0].length;
        long[][] p=new long[n+1][m+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                p[i][j]=mat[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        int cnt=0;
        for(int k=1;k<=Math.min(n,m);k++)
            for(int i=k;i<=n;i++)
                for(int j=k;j<=m;j++){
                    long s=p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k];
                    if(s==x)cnt++;
                }
        return cnt;
    }
}
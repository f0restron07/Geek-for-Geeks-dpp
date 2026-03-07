class Solution {
    static int noOfWays(int m, int n, int x) {
        int[][]d=new int[n+1][x+1];
        d[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=x;j++){
                for(int k=1;k<=m&&k<=j;k++){
                    d[i][j]+=d[i-1][j-k];
                }
            }
        }
        return d[n][x];
    }
}

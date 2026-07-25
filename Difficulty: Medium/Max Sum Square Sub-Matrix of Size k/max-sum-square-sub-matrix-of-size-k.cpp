class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k){
        int n=mat.size();
        vector<vector<int>> p(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i+1][j+1]=p[i][j+1]+p[i+1][j]-p[i][j]+mat[i][j];
            }
        }
        int best=INT_MIN;
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                int s=p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k];
                best=max(best,s);
            }
        }
        return best;
    }
};
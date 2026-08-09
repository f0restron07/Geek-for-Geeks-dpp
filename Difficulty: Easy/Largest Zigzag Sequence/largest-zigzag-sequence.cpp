class Solution {
  public:
    int zigzagSequence(vector<vector<int>>& mat){
        int n=mat.size();
        if(n==1){
            int best=mat[0][0];
            for(int j=0;j<n;j++){
                best=max(best,mat[0][j]);
            }
            return best;
        }
        vector<int> dp(n);
        for(int j=0;j<n;j++){
            dp[j]=mat[0][j];
        }
        for(int i=1;i<n;i++){
            int m1=-1,m2=-1,idx=-1;
            for(int j=0;j<n;j++){
                if(dp[j]>m1){
                    m2=m1;
                    m1=dp[j];
                    idx=j;
                }else if(dp[j]>m2){
                    m2=dp[j];
                }
            }
            vector<int> nd(n);
            for(int j=0;j<n;j++){
                int best=(j==idx)?m2:m1;
                nd[j]=mat[i][j]+best;
            }
            dp=nd;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            ans=max(ans,dp[j]);
        }
        return ans;
    }
};
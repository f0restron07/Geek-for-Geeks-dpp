class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                    continue;
                }
                for(int p=j-1;p>=0;p--){
                    if(mat[i][p]==1){
                        t++;
                        break;
                    }
                }
                for(int p=j+1;p<m;p++){
                    if(mat[i][p]==1){
                        t++;
                        break;
                    }
                }
                for(int p=i-1;p>=0;p--){
                    if(mat[p][j]==1){
                        t++;
                        break;
                    }
                }
                for(int p=i+1;p<n;p++){
                    if(mat[p][j]==1){
                        t++;
                        break;
                    }
                }
            }
        }
        return t;
    }
};
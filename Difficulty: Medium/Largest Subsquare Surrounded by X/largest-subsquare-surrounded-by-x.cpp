class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat){
        int n=mat.size();
        vector<vector<int>> right(n,vector<int>(n,0));
        vector<vector<int>> down(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]=='X'){
                    right[i][j]=1+(j+1<n?right[i][j+1]:0);
                    down[i][j]=1+(i+1<n?down[i+1][j]:0);
                }
            }
        }
        for(int k=n;k>=1;k--){
            for(int i=0;i+k<=n;i++){
                for(int j=0;j+k<=n;j++){
                    if(right[i][j]>=k&&down[i][j]>=k&&right[i+k-1][j]>=k&&down[i][j+k-1]>=k){
                        return k;
                    }
                }
            }
        }
        return 0;
    }
};
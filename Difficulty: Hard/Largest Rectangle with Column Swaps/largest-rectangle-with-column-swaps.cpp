class Solution {
  public:
    int maxArea(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> h(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(mat[i][j]==1){
                    h[i][j]=(i==0?0:h[i-1][j])+1;
                }else{
                    h[i][j]=0;
                }
            }
        }
        int best=0;
        for(int i=0;i<n;i++){
            vector<int> row=h[i];
            sort(row.rbegin(),row.rend());
            for(int t=0;t<m;t++){
                int area=row[t]*(t+1);
                best=max(best,area);
            }
        }
        return best;
    }
};
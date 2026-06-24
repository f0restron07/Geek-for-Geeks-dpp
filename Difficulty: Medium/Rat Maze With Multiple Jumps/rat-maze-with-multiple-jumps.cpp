class Solution {
  public:
    int n;
    vector<vector<int>> bad;
    bool solve(vector<vector<int>>& mat,vector<vector<int>>& sol,int i,int j){
        if(i==n-1&&j==n-1){
            sol[i][j]=1;
            return true;
        }
        if(i>=n||j>=n||mat[i][j]==0||bad[i][j]){
            return false;
        }
        sol[i][j]=1;
        int v=mat[i][j];
        for(int s=1;s<=v;s++){
            if(j+s<n&&solve(mat,sol,i,j+s)){
                return true;
            }
            if(i+s<n&&solve(mat,sol,i+s,j)){
                return true;
            }
        }
        sol[i][j]=0;
        bad[i][j]=1;
        return false;
    }
    vector<vector<int>> shortestDist(vector<vector<int>>& mat){
        n=mat.size();
        vector<vector<int>> sol(n,vector<int>(n,0));
        bad.assign(n,vector<int>(n,0));
        if(solve(mat,sol,0,0)){
            return sol;
        }
        return {{-1}};
    }
};
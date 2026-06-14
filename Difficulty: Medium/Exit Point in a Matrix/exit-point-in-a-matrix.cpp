class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int a=mat.size();
        int b=mat[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int d=0;
        int i=0;
        int j=0;
        while(true){
            if(mat[i][j]==1){
                mat[i][j]=0;
                d=(d+1)%4;
            }
            int p=i+dx[d];
            int q=j+dy[d];
            if(p<0||p>=a||q<0||q>=b){
                break;
            }
            i=p;
            j=q;
        }
        return {i,j};
    }
};
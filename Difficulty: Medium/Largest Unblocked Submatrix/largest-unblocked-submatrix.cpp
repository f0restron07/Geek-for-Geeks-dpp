class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        vector<char> br(n+1,0);
        vector<char> bc(m+1,0);
        for(auto &e:arr){
            br[e[0]]=1;
            bc[e[1]]=1;
        }
        int rowRun=0;
        int best1=0;
        for(int i=1;i<=n;i++){
            if(br[i]){
                rowRun=0;
            }else{
                rowRun++;
                best1=max(best1,rowRun);
            }
        }
        int colRun=0;
        int best2=0;
        for(int j=1;j<=m;j++){
            if(bc[j]){
                colRun=0;
            }else{
                colRun++;
                best2=max(best2,colRun);
            }
        }
        return best1*best2;
    }
};
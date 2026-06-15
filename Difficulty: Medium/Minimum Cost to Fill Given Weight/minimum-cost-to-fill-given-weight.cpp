class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        int a=cost.size();
        vector<int> b(w+1,INT_MAX);
        b[0]=0;
        for(int i=1;i<=w;i++){
            for(int j=1;j<=i&&j<=a;j++){
                if(cost[j-1]!=-1&&b[i-j]!=INT_MAX){
                    b[i]=min(b[i],b[i-j]+cost[j-1]);
                }
            }
        }
        return b[w]==INT_MAX?-1:b[w];
    }
};
class Solution {
  public:
    int minMoves(vector<int>& arr){
        int n=arr.size();
        vector<int> pos(n+1);
        for(int i=0;i<n;i++){
            pos[arr[i]]=i;
        }
        int best=1;
        int cur=1;
        for(int v=2;v<=n;v++){
            if(pos[v]>pos[v-1]){
                cur++;
                best=max(best,cur);
            }else{
                cur=1;
            }
        }
        return n-best;
    }
};
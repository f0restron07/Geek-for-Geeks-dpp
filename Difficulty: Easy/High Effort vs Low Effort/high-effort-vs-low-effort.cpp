class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l){
        int n=h.size();
        int rest=0;
        int work=0;
        for(int i=0;i<n;i++){
            int nrest=max(rest,work);
            int nwork=max(rest,work)+l[i];
            int high=rest+h[i];
            if(i==0){
                high=h[i];
            }
            nwork=max(nwork,high);
            rest=nrest;
            work=nwork;
        }
        return max(rest,work);
    }
};
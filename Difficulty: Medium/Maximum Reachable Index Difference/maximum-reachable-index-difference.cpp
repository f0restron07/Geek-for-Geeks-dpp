class Solution {
  public:
    int maxIndexDifference(string &s){
        int n=s.size();
        vector<int> best(26,-1);
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int d=s[i]-'a';
            int reach;
            if(d<25&&best[d+1]!=-1){
                reach=best[d+1];
            }else{
                reach=i;
            }
            if(reach>best[d]){
                best[d]=reach;
            }
            if(d==0){
                if(reach-i>ans){
                    ans=reach-i;
                }
            }
        }
        return ans;
    }
};
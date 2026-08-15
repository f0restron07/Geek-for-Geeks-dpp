class Solution {
  public:
    string s;
    int dd;
    int dp[11][2][2];
    bool vis[11][2][2];
    int solve(int pos,int tight,int started){
        if(pos==(int)s.size()){
            return started?1:0;
        }
        if(vis[pos][tight][started]){
            return dp[pos][tight][started];
        }
        int lim=tight?(s[pos]-'0'):9;
        int res=0;
        for(int dig=0;dig<=lim;dig++){
            int nstarted=started||(dig!=0);
            if(nstarted&&dig==dd){
                continue;
            }
            res+=solve(pos+1,tight&&(dig==lim),nstarted);
        }
        vis[pos][tight][started]=true;
        dp[pos][tight][started]=res;
        return res;
    }
    int countWithout(int n,int d){
        if(n==0){
            return 0;
        }
        s=to_string(n);
        dd=d;
        memset(vis,0,sizeof(vis));
        return solve(0,1,0);
    }
};
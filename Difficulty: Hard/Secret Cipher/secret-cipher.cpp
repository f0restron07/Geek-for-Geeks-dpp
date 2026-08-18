class Solution {
  public:
    string compress(string &s){
        int n=s.size();
        vector<int> z(n,0);
        z[0]=n;
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r){
                z[i]=min(r-i,z[i-l]);
            }
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        const int INF=1e9;
        vector<int> rf(n+1,INF);
        rf[n]=0;
        for(int L=n-1;L>=0;L--){
            int best=INF;
            if(rf[L+1]!=INF){
                best=min(best,1+rf[L+1]);
            }
            if(L>0&&2*L<=n&&z[L]>=L&&rf[2*L]!=INF){
                best=min(best,1+rf[2*L]);
            }
            rf[L]=best;
        }
        string res;
        int L=0;
        while(L<n){
            if(L>0&&2*L<=n&&z[L]>=L&&rf[2*L]!=INF&&1+rf[2*L]==rf[L]){
                res+='*';
                L=2*L;
            }else{
                res+=s[L];
                L++;
            }
        }
        return res;
    }
};
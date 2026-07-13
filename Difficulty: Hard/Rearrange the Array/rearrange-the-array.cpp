class Solution {
  public:
    int minOperations(vector<int> &b) {
        const long long M=1000000007;
        int n=b.size();
        vector<char> vis(n+1,0);
        map<int,int> mx;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                continue;
            }
            int len=0;
            int j=i;
            while(!vis[j]){
                vis[j]=1;
                j=b[j-1];
                len++;
            }
            int t=len;
            for(int p=2;(long long)p*p<=t;p++){
                if(t%p==0){
                    int cnt=0;
                    while(t%p==0){
                        t/=p;
                        cnt++;
                    }
                    mx[p]=max(mx[p],cnt);
                }
            }
            if(t>1){
                mx[t]=max(mx[t],1);
            }
        }
        long long ans=1;
        for(auto &e:mx){
            long long p=e.first;
            for(int c=0;c<e.second;c++){
                ans=ans*p%M;
            }
        }
        return (int)ans;
    }
};
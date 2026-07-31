class Solution {
  public:
    int countSubsets(vector<int> &arr){
        const long long M=1000000007;
        vector<int> primes={2,3,5,7,11,13,17,19,23,29};
        auto getMask=[&](int x)->int{
            int mask=0;
            for(int i=0;i<10;i++){
                int p=primes[i];
                if(x%p==0){
                    x/=p;
                    if(x%p==0){
                        return -1;
                    }
                    mask|=(1<<i);
                }
            }
            return (x==1)?mask:-1;
        };
        long long cnt[31]={0};
        for(int x:arr){
            cnt[x]++;
        }
        int full=1<<10;
        vector<long long> dp(full,0);
        dp[0]=1;
        for(int v=2;v<=30;v++){
            if(cnt[v]==0){
                continue;
            }
            int m=getMask(v);
            if(m<0){
                continue;
            }
            long long c=cnt[v]%M;
            vector<long long> nd=dp;
            for(int mask=0;mask<full;mask++){
                if(dp[mask]==0){
                    continue;
                }
                if((mask&m)==0){
                    nd[mask|m]=(nd[mask|m]+dp[mask]*c)%M;
                }
            }
            dp=nd;
        }
        long long total=0;
        for(int mask=1;mask<full;mask++){
            total=(total+dp[mask])%M;
        }
        long long pw=1;
        for(long long i=0;i<cnt[1];i++){
            pw=pw*2%M;
        }
        return (int)(total*pw%M);
    }
};




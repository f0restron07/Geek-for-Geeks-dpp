class Solution {
  public:
    int minCost(int n, int i, int d, int c){
        const long long INF=LLONG_MAX;
        vector<long long> dp(n+1,INF);
        dp[0]=0;
        deque<pair<int,long long>> dq;
        int ptr=0;
        for(int k=1;k<=n;k++){
            while(ptr<k){
                long long g=dp[ptr]+2LL*d*ptr;
                while(!dq.empty()&&dq.back().second>=g){
                    dq.pop_back();
                }
                dq.push_back({ptr,g});
                ptr++;
            }
            int low=(k+1)/2;
            while(!dq.empty()&&dq.front().first<low){
                dq.pop_front();
            }
            long long best=dp[k-1]+i;
            if(k%2==0&&dp[k/2]+c<best){
                best=dp[k/2]+c;
            }
            if(!dq.empty()){
                long long cand=dq.front().second+c-(long long)k*d;
                if(cand<best){
                    best=cand;
                }
            }
            dp[k]=best;
        }
        return (int)dp[n];
    }
};
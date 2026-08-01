class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k){
        vector<long long> d(n+1,0);
        int m=a.size();
        for(int i=0;i<m;i++){
            d[a[i]]+=k[i];
            d[b[i]+1]-=k[i];
        }
        long long cur=0;
        long long best=0;
        for(int i=0;i<n;i++){
            cur+=d[i];
            best=max(best,cur);
        }
        return (int)best;
    }
};
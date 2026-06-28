class Solution {
  public:
    int countStrings(int n, int k) {
        const long long M=1000000007;
        vector<long long> a0(k+1,0),a1(k+1,0),b0(k+1,0),b1(k+1,0);
        a0[0]=1;
        a1[0]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=k;j++){
                b0[j]=(a0[j]+a1[j])%M;
                long long v=a0[j];
                if(j>0){
                    v=(v+a1[j-1])%M;
                }
                b1[j]=v;
            }
            swap(a0,b0);
            swap(a1,b1);
        }
        return (int)((a0[k]+a1[k])%M);
    }
};
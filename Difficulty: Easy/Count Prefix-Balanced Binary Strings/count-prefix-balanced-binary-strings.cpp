class Solution {
  public:
    long long power(long long a,long long b,long long m){
        long long r=1;
        a%=m;
        while(b>0){
            if(b&1){
                r=r*a%m;
            }
            a=a*a%m;
            b>>=1;
        }
        return r;
    }
    int prefixStrings(int n){
        const long long M=1000000007;
        int sz=2*n;
        vector<long long> f(sz+1);
        f[0]=1;
        for(int i=1;i<=sz;i++){
            f[i]=f[i-1]*i%M;
        }
        long long c=f[sz]*power(f[n],M-2,M)%M*power(f[n],M-2,M)%M;
        long long cat=c*power(n+1,M-2,M)%M;
        return (int)cat;
    }
};
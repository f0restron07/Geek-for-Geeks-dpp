class Solution {
  public:
    int aModInv(long long a,long long b,long long c){
        long long d=1;
        a%=c;
        while(b>0){
            if(b&1){
                d=d*a%c;
            }
            a=a*a%c;
            b>>=1;
        }
        return d;
    }
    int computeValue(int n){
        const long long c=1000000007;
        int a=2*n;
        vector<long long> f(a+1);
        f[0]=1;
        for(int i=1;i<=a;i++){
            f[i]=f[i-1]*i%c;
        }
        long long d=aModInv(f[n],c-2,c);
        long long e=f[a]*d%c*d%c;
        return (int)e;
    }
};
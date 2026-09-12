class Solution {
  public:
    int maxProduct(vector<int> &arr, int k){
        const long long NEG=LLONG_MIN;
        const long long POS=LLONG_MAX;
        vector<long long> mx(k+1,NEG);
        vector<long long> mn(k+1,POS);
        mx[0]=1;
        mn[0]=1;
        for(int x:arr){
            for(int j=k;j>=1;j--){
                if(mx[j-1]!=NEG){
                    long long a=mx[j-1]*x;
                    long long b=mn[j-1]*x;
                    long long nmax=max(a,b);
                    long long nmin=min(a,b);
                    if(nmax>mx[j]){
                        mx[j]=nmax;
                    }
                    if(nmin<mn[j]){
                        mn[j]=nmin;
                    }
                }
            }
        }
        return (int)mx[k];
    }
};
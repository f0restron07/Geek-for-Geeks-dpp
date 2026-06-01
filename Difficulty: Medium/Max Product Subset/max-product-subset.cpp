class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return arr[0];
        const int MOD=1e9+7;
        int neg=0,zero=0,pos=0,maxNeg=INT_MIN;
        for(int x:arr){
            if(x==0)zero++;
            else if(x<0){neg++;maxNeg=max(maxNeg,x);}
            else pos++;
        }
        if(zero==n)return 0;
        if(neg==1&&pos==0&&zero>0)return 0;
        long long p=1;
        bool skipped=(neg%2==0);
        for(int x:arr){
            if(x==0)continue;
            if(!skipped&&x==maxNeg){skipped=true;continue;}
            long long v=x<0?(MOD+x):x;
            p=(p*v)%MOD;
        }
        return (int)p;
    }
};
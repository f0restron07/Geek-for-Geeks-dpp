class Solution {
  public:
    int minProd(vector<int>& arr){
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        int negCount=0;
        int zeroCount=0;
        int prod=1;
        int maxNeg=INT_MIN;
        bool hasNonZero=false;
        for(int x:arr){
            if(x==0){
                zeroCount++;
                continue;
            }
            hasNonZero=true;
            if(x<0){
                negCount++;
                maxNeg=max(maxNeg,x);
            }
            prod*=x;
        }
        if(!hasNonZero){
            return 0;
        }
        if(negCount%2==0){
            if(negCount==0){
                int mn=INT_MAX;
                for(int x:arr){
                    mn=min(mn,x);
                }
                return mn;
            }
            prod/=maxNeg;
        }
        return prod;
    }
};
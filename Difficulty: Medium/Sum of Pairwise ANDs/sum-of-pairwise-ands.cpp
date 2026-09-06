class Solution {
  public:
    long long pairAndSum(vector<int> &arr){
        long long total=0;
        for(int b=0;b<30;b++){
            long long c=0;
            for(int x:arr){
                if(x&(1<<b)){
                    c++;
                }
            }
            total+=(c*(c-1)/2)*(1LL<<b);
        }
        return total;
    }
};
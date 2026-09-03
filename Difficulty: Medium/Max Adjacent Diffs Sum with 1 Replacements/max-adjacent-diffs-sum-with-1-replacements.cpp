class Solution {
  public:
    int maxDiffSum(vector<int>& arr){
        int n=arr.size();
        if(n==1){
            return 0;
        }
        long long keep=0;
        long long rep=0;
        for(int i=1;i<n;i++){
            long long nk=max(keep+abs(arr[i]-arr[i-1]),rep+abs((long long)arr[i]-1));
            long long nr=max(keep+abs(1-arr[i-1]),rep+abs(1LL-1));
            keep=nk;
            rep=nr;
        }
        return (int)max(keep,rep);
    }
};
class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k){
        int n=arr.size();
        vector<long long> me(n,0);
        me[0]=arr[0];
        for(int i=1;i<n;i++){
            me[i]=max((long long)arr[i],me[i-1]+arr[i]);
        }
        long long windowSum=0;
        for(int i=0;i<k;i++){
            windowSum+=arr[i];
        }
        long long best=windowSum;
        for(int i=k;i<n;i++){
            windowSum+=arr[i]-arr[i-k];
            best=max(best,windowSum);
            best=max(best,windowSum+me[i-k]);
        }
        return (int)best;
    }
};
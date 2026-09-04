class Solution {
  public:
    int maxFruits(vector<int>& arr, int m){
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<m;i++){
            sum+=arr[i];
        }
        long long best=sum;
        for(int i=1;i<n;i++){
            sum-=arr[i-1];
            sum+=arr[(i+m-1)%n];
            best=max(best,sum);
        }
        return (int)best;
    }
};
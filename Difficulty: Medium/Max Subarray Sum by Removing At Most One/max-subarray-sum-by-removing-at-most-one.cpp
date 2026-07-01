class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int a=arr.size();
        long long b=arr[0],c=-1e18,d=arr[0];
        for(int e=1;e<a;e++){
            c=max(b,c+arr[e]);
            b=max((long long)arr[e],b+arr[e]);
            d=max({d,b,c});
        }
        return (int)d;
    }
};
class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int s=0;
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i]-arr[i-1]<k){
                s+=arr[i]+arr[i-1];
                i--;
            }
        }
        return s;
    }
};
class Solution {
  public:
    int countPairs(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long c=0;
        int i=0;
        for(int j=0;j<n;j++){
            while(arr[j]-arr[i]>=k){
                i++;
            }
            c+=j-i;
        }
        return (int)c;
    }
};
class Solution {
  public:
    int minSubsets(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int c=1;
        for(int i=1;i<(int)arr.size();i++){
            if(arr[i]!=arr[i-1]+1){
                c++;
            }
        }
        return c;
    }
};
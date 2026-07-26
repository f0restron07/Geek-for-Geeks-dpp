class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> res;
        int i=0;
        int cnt=1;
        while(i<n){
            vector<int> level;
            for(int j=0;j<cnt&&i<n;j++){
                level.push_back(arr[i]);
                i++;
            }
            sort(level.begin(),level.end());
            res.push_back(level);
            cnt*=2;
        }
        return res;
    }
};
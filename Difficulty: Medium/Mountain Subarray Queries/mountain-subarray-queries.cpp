class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> upReach(n), downEnd(n);
        upReach[n - 1] = n - 1;
        downEnd[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            upReach[i] = (arr[i] <= arr[i + 1]) ? upReach[i + 1] : i;
            downEnd[i] = (arr[i] >= arr[i + 1]) ? downEnd[i + 1] : i;
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int peak = upReach[l];
            if (peak >= r) ans.push_back(true);      
            else ans.push_back(downEnd[peak] >= r);   
        }
        return ans;
    }
};
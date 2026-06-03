class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]].push_back(i);
        vector<int> res;
        for(auto& q:queries){
            int l=q[0],r=q[1],x=q[2];
            auto it=mp.find(x);
            if(it==mp.end()){res.push_back(0);continue;}
            auto& v=it->second;
            res.push_back(upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l));
        }
        return res;
    }
};
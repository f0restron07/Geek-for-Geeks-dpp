class Solution{
  public:
    vector<int> constructList(vector<vector<int>> &queries){
        vector<int> a;
        a.push_back(0);
        int b=0;
        int n=queries.size();
        for(int i=0;i<n;i++){
            if(queries[i][0]==0){
                a.push_back(queries[i][1]^b);
            }else{
                b^=queries[i][1];
            }
        }
        for(int i=0;i<(int)a.size();i++){
            a[i]^=b;
        }
        sort(a.begin(),a.end());
        return a;
    }
};
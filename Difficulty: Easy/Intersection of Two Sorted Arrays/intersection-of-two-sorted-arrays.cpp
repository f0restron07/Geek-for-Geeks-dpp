class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> r;
        int n=a.size(),m=b.size(),i=0,j=0;
        while(i<n&&j<m){
            if(a[i]<b[j])i++;
            else if(a[i]>b[j])j++;
            else{
                if(r.empty()||r.back()!=a[i])r.push_back(a[i]);
                i++;j++;
            }
        }
        return r;
    }
};
class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
        unordered_map<int,int> r;
        for(int i=0;i<m;i++){
            r[b[i]]=i;
        }
        vector<int> t;
        for(int x:a){
            auto it=r.find(x);
            if(it==r.end()){
                continue;
            }
            int v=it->second;
            auto p=lower_bound(t.begin(),t.end(),v);
            if(p==t.end()){
                t.push_back(v);
            }else{
                *p=v;
            }
        }
        int lcs=t.size();
        return (n-lcs)+(m-lcs);
    }
};
class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n=s.size();
        if(n%k!=0){
            return false;
        }
        unordered_map<string,int> m;
        for(int i=0;i<n;i+=k){
            m[s.substr(i,k)]++;
        }
        if(m.size()==1){
            return true;
        }
        if(m.size()==2){
            for(auto &p:m){
                if(p.second==1){
                    return true;
                }
            }
        }
        return false;
    }
};
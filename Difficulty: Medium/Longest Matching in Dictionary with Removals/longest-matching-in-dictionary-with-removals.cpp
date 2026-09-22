class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d){
        vector<vector<int>> pos(26);
        for(int i=0;i<(int)s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        auto isSubseq=[&](const string& w)->bool{
            int cur=-1;
            for(char ch:w){
                auto& v=pos[ch-'a'];
                auto it=upper_bound(v.begin(),v.end(),cur);
                if(it==v.end()){
                    return false;
                }
                cur=*it;
            }
            return true;
        };
        string best="";
        for(auto& w:d){
            if(w.size()<best.size()){
                continue;
            }
            if(w.size()==best.size()&&w>=best){
                continue;
            }
            if(isSubseq(w)){
                best=w;
            }
        }
        return best;
    }
};
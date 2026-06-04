class Solution {
  public:
    int maxSubstring(string &s) {
        int best=INT_MIN,cur=0;
        for(char c:s){
            int v=(c=='0')?1:-1;
            cur=max(v,cur+v);
            best=max(best,cur);
        }
        return best;
    }
};
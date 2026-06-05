class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n=s.size();
        bool isPow2=(n>0)&&((n&(n-1))==0);
        k=isPow2?k/2:k*2;
        if(k>=n)return "-1";
        if(k==0)return s;
        string st;
        for(char c:s){
            while(!st.empty()&&k>0&&st.back()>c){st.pop_back();k--;}
            st.push_back(c);
        }
        while(k--)st.pop_back();
        return st;
    }
};
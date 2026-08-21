class Solution {
  public:
    int transform(string &s1, string &s2){
        int n=s1.size();
        int m=s2.size();
        if(n!=m){
            return -1;
        }
        vector<int> f(256,0);
        for(char c:s1){
            f[(unsigned char)c]++;
        }
        for(char c:s2){
            f[(unsigned char)c]--;
        }
        for(int i=0;i<256;i++){
            if(f[i]!=0){
                return -1;
            }
        }
        int i=n-1;
        int j=m-1;
        int moves=0;
        while(i>=0){
            if(s1[i]==s2[j]){
                i--;
                j--;
            }else{
                i--;
                moves++;
            }
        }
        return moves;
    }
};
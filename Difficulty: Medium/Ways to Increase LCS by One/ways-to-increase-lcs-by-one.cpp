class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> pre(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    pre[i][j]=pre[i-1][j-1]+1;
                }else{
                    pre[i][j]=max(pre[i-1][j],pre[i][j-1]);
                }
            }
        }
        vector<vector<int>> suf(n+2,vector<int>(m+2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    suf[i][j]=suf[i+1][j+1]+1;
                }else{
                    suf[i][j]=max(suf[i+1][j],suf[i][j+1]);
                }
            }
        }
        int L=pre[n][m];
        int cnt=0;
        for(int p=0;p<=n;p++){
            vector<int> best(26,0);
            for(int k=0;k<m;k++){
                int c=s2[k]-'a';
                int v=pre[p][k]+1+suf[p][k+1];
                best[c]=max(best[c],v);
            }
            for(int c=0;c<26;c++){
                if(best[c]==L+1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
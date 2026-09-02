class Solution {
  public:
    int solve(int n, string s){
        vector<int> seen(26,0);
        vector<int> holding(26,0);
        int avail=n;
        int rejected=0;
        for(char ch:s){
            int c=ch-'A';
            if(!seen[c]){
                seen[c]=1;
                if(avail>0){
                    avail--;
                    holding[c]=1;
                }else{
                    rejected++;
                }
            }else{
                if(holding[c]){
                    avail++;
                    holding[c]=0;
                }
            }
        }
        return rejected;
    }
};
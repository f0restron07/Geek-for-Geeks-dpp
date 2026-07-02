class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n=arr.size();
        if(n>=k){
            return true;
        }
        vector<char> dp(k,0);
        for(int x:arr){
            vector<char> nx=dp;
            int r=x%k;
            if(r==0){
                return true;
            }
            nx[r]=1;
            for(int j=0;j<k;j++){
                if(dp[j]){
                    int nr=(j+r)%k;
                    if(nr==0){
                        return true;
                    }
                    nx[nr]=1;
                }
            }
            dp=nx;
        }
        return dp[0];
    }
};
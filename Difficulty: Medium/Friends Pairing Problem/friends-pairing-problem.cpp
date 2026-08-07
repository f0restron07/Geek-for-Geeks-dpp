class Solution {
  public:
    int countFriendsPairings(int n){
        if(n<=2){
            return n;
        }
        long long a=1;
        long long b=2;
        for(int i=3;i<=n;i++){
            long long c=b+(long long)(i-1)*a;
            a=b;
            b=c;
        }
        return (int)b;
    }
};
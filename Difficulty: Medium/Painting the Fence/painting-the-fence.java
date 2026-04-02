class Solution{
    int countWays(int n,int k){
        if(n==1){
            return k;
        }
        int a=k;
        int b=k*(k-1);
        for(int i=3;i<=n;i++){
            int c=b;
            b=(a+b)*(k-1);
            a=c;
        }
        return a+b;
    }
}
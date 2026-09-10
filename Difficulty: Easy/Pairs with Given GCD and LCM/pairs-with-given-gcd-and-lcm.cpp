class Solution {
  public:
    int gcd(int a,int b){
        while(b){
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    int pairCount(int x, int y){
        if(y%x!=0){
            return 0;
        }
        int k=y/x;
        int cnt=0;
        for(int d=1;(long long)d*d<=k;d++){
            if(k%d==0){
                int e=k/d;
                if(gcd(d,e)==1){
                    if(d==e){
                        cnt+=1;
                    }else{
                        cnt+=2;
                    }
                }
            }
        }
        return cnt;
    }
};
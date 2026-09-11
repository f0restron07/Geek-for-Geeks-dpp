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
    int sameMod(vector<int> &arr){
        int n=arr.size();
        int g=0;
        for(int i=1;i<n;i++){
            g=gcd(g,abs(arr[i]-arr[i-1]));
        }
        if(g==0){
            return -1;
        }
        int cnt=0;
        for(int d=1;(long long)d*d<=g;d++){
            if(g%d==0){
                cnt++;
                if(d!=g/d){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
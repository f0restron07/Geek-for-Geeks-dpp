class Solution {
  public:
    int getCount(int n) {
        int c=0;
        for(long long L=2;L*(L-1)/2<n;L++){
            long long r=n-L*(L-1)/2;
            if(r%L==0){
                c++;
            }
        }
        return c;
    }
};
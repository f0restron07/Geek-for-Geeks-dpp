class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        int a=arr.size();
        vector<int> b(a);
        long long c=0,d=0;
        int e=0;
        for(int i=0;i<a;i++){
            if(i==0){
                b[i]=0;
                continue;
            }
            d+=arr[i];
            if(i%2==0){
                c+=arr[e];
                d-=arr[e+1];
                e++;
            }
            long long f=arr[e];
            long long g=e;
            long long h=i-e;
            b[i]=(int)((d-h*f)+(g*f-c));
        }
        return b;
    }
};
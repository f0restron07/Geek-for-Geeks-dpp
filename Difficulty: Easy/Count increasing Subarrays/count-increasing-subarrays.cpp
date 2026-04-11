class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int a=arr.size(),b=0,c=1;
        for(int i=1;i<a;i++){
            if(arr[i]>arr[i-1]){
                c++;
            }else{
                b+=c*(c-1)/2;
                c=1;
            }
        }
        b+=c*(c-1)/2;
        return b;
    }
};
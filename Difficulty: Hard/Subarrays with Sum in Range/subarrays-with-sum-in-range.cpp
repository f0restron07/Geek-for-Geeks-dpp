class Solution {
  public:
    long long atMost(vector<int>& arr,long long x){
        long long c=0;
        long long sum=0;
        int i=0;
        for(int j=0;j<(int)arr.size();j++){
            sum+=arr[j];
            while(sum>x){
                sum-=arr[i];
                i++;
            }
            c+=j-i+1;
        }
        return c;
    }
    int countSubarray(vector<int>& arr,int l,int r){
        return (int)(atMost(arr,r)-atMost(arr,l-1));
    }
};
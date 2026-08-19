class Solution {
  public:
    long long atMost(vector<int>& arr,int x){
        int n=arr.size();
        long long c=0;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]<=x){
                    c+=k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return c;
    }
    int countTriplets(vector<int> &arr,int l,int r){
        sort(arr.begin(),arr.end());
        return (int)(atMost(arr,r)-atMost(arr,l-1));
    }
};
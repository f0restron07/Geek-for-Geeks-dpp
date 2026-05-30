class Solution {
  public:
    void replaceElements(vector<int>& arr){
    vector<int> t(arr);
    int n=arr.size();
    arr[0]=t[0]^t[1];
    arr[n-1]=t[n-2]^t[n-1];
    for(int i=1;i<n-1;i++) arr[i]=t[i-1]^t[i+1];
}
};
class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> lMax(n),lMin(n),rMax(n),rMin(n);
        int curMax=arr[0],curMin=arr[0];
        lMax[0]=arr[0];
        lMin[0]=arr[0];
        for(int i=1;i<n;i++){
            curMax=max(arr[i],curMax+arr[i]);
            lMax[i]=max(lMax[i-1],curMax);
            curMin=min(arr[i],curMin+arr[i]);
            lMin[i]=min(lMin[i-1],curMin);
        }
        curMax=arr[n-1];
        curMin=arr[n-1];
        rMax[n-1]=arr[n-1];
        rMin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            curMax=max(arr[i],curMax+arr[i]);
            rMax[i]=max(rMax[i+1],curMax);
            curMin=min(arr[i],curMin+arr[i]);
            rMin[i]=min(rMin[i+1],curMin);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int a=abs(lMax[i]-rMin[i+1]);
            int b=abs(lMin[i]-rMax[i+1]);
            ans=max(ans,max(a,b));
        }
        return ans;
    }
};
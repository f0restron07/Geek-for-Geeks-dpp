class Solution {
    public int maxOnes(int arr[], int k) {
        int l=0,z=0,r=0,n=arr.length,ans=0;
        for(;r<n;r++){
            if(arr[r]==0)z++;
            while(z>k){if(arr[l]==0)z--;l++;}
            ans=Math.max(ans,r-l+1);
        }
        return ans;
    }
}
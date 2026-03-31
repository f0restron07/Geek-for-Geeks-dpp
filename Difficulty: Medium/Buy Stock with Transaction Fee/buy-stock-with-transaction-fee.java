class Solution {
    public int maxProfit(int arr[], int k) {
        int n=arr.length;
        if(n==0)return 0;
        int a=0,b=-arr[0];
        for(int i=1;i<n;i++){
            int c=Math.max(a,b+arr[i]-k);
            int d=Math.max(b,a-arr[i]);
            a=c;
            b=d;
        }
        return a;
    }
}
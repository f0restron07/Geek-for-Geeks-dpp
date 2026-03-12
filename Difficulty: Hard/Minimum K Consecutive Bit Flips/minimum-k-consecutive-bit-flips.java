class Solution {
    public int kBitFlips(int[] arr, int k) {
        // code here
        int n=arr.length;
        int c=0;
        int f=0;
        for(int i=0;i<n;i++) {
            if(i>=k) {
                if(arr[i-k]==2) {
                    f^=1;
                    arr[i-k]=1;
                }
            }
            int v=arr[i];
            if((v^f)==0) {
                if(i+k>n) {
                    return-1;
                }
                arr[i]=2;
                f^=1;
                c++;
            }
        }

        return c;
    }
}

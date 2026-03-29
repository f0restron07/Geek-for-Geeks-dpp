class Solution {
    public int countPartitions(int[] arr,int diff) {
        int n=arr.length,s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
        }
        if(diff>s){
            return 0;
        }
        if(((s+diff)&1)==1){
            return 0;
        }
        int t=(s+diff)>>1;
        int[] a=new int[t+1];
        a[0]=1;
        for(int i=0;i<n;i++){
            for(int j=t;j>=arr[i];j--){
                a[j]+=a[j-arr[i]];
            }
        }
        return a[t];
    }
}
class Solution{
    public int minSwaps(int[] a){
        int n=a.length,k=0;
        for(int x:a){
            k+=x;
        }
        if(k==0){
            return -1;
        }
        int c=0;
        for(int i=0;i<k;i++){
            c+=a[i];
        }
        int b=c;
        for(int i=k;i<n;i++){
            c+=a[i]-a[i-k];
            if(c>b){
                b=c;
            }
        }
        return k-b;
    }
}
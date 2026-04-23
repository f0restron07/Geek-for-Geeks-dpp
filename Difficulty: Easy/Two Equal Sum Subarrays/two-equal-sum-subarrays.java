class Solution {
    public boolean canSplit(int[] arr) {
        long s=0;
        for(int x:arr) s+=x;
        if((s&1)==1) return false;
        long h=s>>1, p=0;
        for(int i=0;i<arr.length-1;i++){
            p+=arr[i];
            if(p==h) return true;
        }
        return false;
    }
}
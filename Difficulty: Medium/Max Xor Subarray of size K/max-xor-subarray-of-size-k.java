class Solution {
    public int maxSubarrayXOR(int[] a, int k) {
        int x=0,m,i;
        for(i=0;i<k;i++)x^=a[i];
        m=x;
        for(;i<a.length;i++){
            x^=a[i-k]^a[i];
            if(x>m)m=x;
        }
        return m;
    }
}
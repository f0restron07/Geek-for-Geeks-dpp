class Solution{
    public int findSmallest(int[] a){
        Arrays.sort(a);
        int b=1;
        for(int i=0;i<a.length;i++){
            if(a[i]>b){
                break;
            }
            b+=a[i];
        }
        return b;
    }
}
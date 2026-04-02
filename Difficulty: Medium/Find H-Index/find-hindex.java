class Solution {
    public int hIndex(int[] citations) {
        int n=citations.length;
        int[] c=new int[n+1];
        for(int x:citations){
            if(x>=n){
                c[n]++;
            }else{
                c[x]++;
            }
        }
        int s=0;
        for(int i=n;i>=0;i--){
            s+=c[i];
            if(s>=i){
                return i;
            }
        }
        return 0;
    }
}
class Solution {
    public boolean checkElements(int a,int b,int[] c){
        int d=0;
        for(int i=0;i<c.length;i++){
            if(c[i]>=a&&c[i]<=b){
                d++;
            }
        }
        return d==b-a+1;
    }
}
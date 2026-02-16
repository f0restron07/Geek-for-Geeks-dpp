class Solution{
    static boolean canAttend(int[][] a){
        java.util.Arrays.sort(a,(b,c)->b[0]-c[0]);
        int i=1;
        while(i<a.length){
            if(a[i][0]<a[i-1][1]){
                return false;
            }
            i++;
        }
        return true;
    }
}

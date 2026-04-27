class Solution {
    public int smallestSubstring(String s) {
        int n=s.length(),r=-1;
        int[]f=new int[3];
        for(int i=0,j=0;j<n;j++){
            f[s.charAt(j)-'0']++;
            while(f[0]>0&&f[1]>0&&f[2]>0){
                r=r<0?j-i+1:Math.min(r,j-i+1);
                f[s.charAt(i++)-'0']--;
            }
        }
        return r;
    }
}
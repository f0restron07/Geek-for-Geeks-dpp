class Solution{
    public int longestSubstr(String s,int k){
        int[]f=new int[26];
        int l=0,m=0,n=s.length();
        for(int r=0;r<n;r++){
            m=Math.max(m,++f[s.charAt(r)-'A']);
            if(r-l+1-m>k)f[s.charAt(l++)-'A']--;
        }
        return n-l;
    }
}
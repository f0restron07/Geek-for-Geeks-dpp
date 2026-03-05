class Solution {
    public int longestKSubstr(String s, int k) {
        int[] f=new int[26];
        int l=0,m=-1,d=0,i;
        for(i=0;i<s.length();i++){
            if(f[s.charAt(i)-'a']++==0)d++;
            while(d>k)if(--f[s.charAt(l++)-'a']==0)d--;
            if(d==k)m=Math.max(m,i-l+1);
        }
        return m;
    }
}
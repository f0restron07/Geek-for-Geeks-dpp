class Solution {
    public String minWindow(String s, String p) {
        int[] f=new int[26];
        int i,l=0,c=0,m=Integer.MAX_VALUE,st=-1;
        for(i=0;i<p.length();i++)f[p.charAt(i)-'a']++;
        for(i=0;i<s.length();i++){
            if(f[s.charAt(i)-'a']-->0)c++;
            while(c==p.length()){
                if(i-l+1<m){m=i-l+1;st=l;}
                if(++f[s.charAt(l++)-'a']>0)c--;
            }
        }
        return st==-1?"":s.substring(st,st+m);
    }
}
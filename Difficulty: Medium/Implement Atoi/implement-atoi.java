class Solution {
    public int myAtoi(String s) {
        int n=s.length(),i=0;
       
        while(i<n && s.charAt(i)==' ') i++;
        
        if(i==n) return 0;
        
        int sign=1;
        if(s.charAt(i)=='-' || s.charAt(i)=='+'){
            sign = s.charAt(i)=='-' ? -1 : 1;
            i++;
        }
        
        long result=0;
        while(i<n && s.charAt(i)>='0' && s.charAt(i)<='9'){
            result = result*10 + (s.charAt(i)-'0');
            
            if(sign==1 && result>Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if(sign==-1 && -result<Integer.MIN_VALUE) return Integer.MIN_VALUE;
            
            i++;
        }
        
        return (int)(sign*result);
    }
}
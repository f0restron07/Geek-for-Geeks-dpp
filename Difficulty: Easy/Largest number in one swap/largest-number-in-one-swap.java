class Solution{
    public String largestSwap(String s){
        char[] c=s.toCharArray();
        int n=c.length;
        int[] m=new int[n];
        m[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            m[i]=c[i]>c[m[i+1]]?i:m[i+1];
        }
        for(int i=0;i<n-1;i++){
            if(c[i]<c[m[i+1]]){
                char t=c[i];c[i]=c[m[i+1]];c[m[i+1]]=t;
                break;
            }
        }
        return new String(c);
    }
}
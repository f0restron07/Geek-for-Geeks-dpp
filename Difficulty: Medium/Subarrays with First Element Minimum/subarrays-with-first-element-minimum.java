class Solution {
    public int countSubarrays(int[] a) {
        int n=a.length,c=0,t=-1;
        int[] s=new int[n],nxt=new int[n];
        for(int i=0;i<n;i++){
            nxt[i]=n;
        }
        for(int i=0;i<n;i++){
            while(t>=0&&a[s[t]]>a[i]){
                nxt[s[t--]]=i;
            }
            s[++t]=i;
        }
        for(int i=0;i<n;i++){
            c+=nxt[i]-i;
        }
        return c;
    }
}
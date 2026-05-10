class Solution{
    public int maxProfit(int x,int y,int[] a,int[] b){
        int n=a.length;
        long s=0;
        for(int i=0;i<n;i++){s+=a[i];}
        int o=10000;
        int[] c=new int[(o<<1)+1];
        for(int i=0;i<n;i++){c[b[i]-a[i]+o]++;}
        int lo=Math.max(0,n-x),hi=Math.min(n,y);
        long t=0;
        int k=0;
        for(int d=(o<<1);d>=0&&k<hi;d--){
            int v=d-o,r=c[d];
            if(r==0){continue;}
            if(k<lo){
                int u=Math.min(r,lo-k);
                t+=(long)v*u;
                k+=u;
                r-=u;
            }
            if(r>0&&v>0&&k<hi){
                int u=Math.min(r,hi-k);
                t+=(long)v*u;
                k+=u;
            }
        }
        return (int)(s+t);
    }
}
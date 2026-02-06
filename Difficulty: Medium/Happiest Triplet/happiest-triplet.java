class Solution {
    int[] smallestDiff(int a[], int b[], int c[]) {
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);
        
        int i=0, j=0, k=0, d=Integer.MAX_VALUE, s=Integer.MAX_VALUE;
        int[] r = new int[3];
        
        while(i<a.length && j<b.length && k<c.length) {
            int n=Math.min(a[i],Math.min(b[j],c[k]));
            int x=Math.max(a[i],Math.max(b[j],c[k]));
            int g=x-n;
            int u=a[i]+b[j]+c[k];
            if(g<d || (g==d && u<s)) {
                d=g;
                s=u;
                r[0]=x;
                r[2]=n;
                r[1]=u-x-n;
        }
            if(a[i]==n) i++;
            else if(b[j]==n) j++;
            else k++;
        }
        
        return r;
    }
}
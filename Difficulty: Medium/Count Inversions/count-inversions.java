class Solution{
    static int inversionCount(int a[]){
        return ms(a,0,a.length-1);
    }
    static int ms(int[]a,int l,int r){
        if(l>=r)return 0;
        int m=(l+r)/2,c=ms(a,l,m)+ms(a,m+1,r);
        int[]t=new int[r-l+1];
        int i=l,j=m+1,k=0;
        while(i<=m&&j<=r){
            if(a[i]<=a[j])t[k++]=a[i++];
            else{c+=m-i+1;t[k++]=a[j++];}
        }
        while(i<=m)t[k++]=a[i++];
        while(j<=r)t[k++]=a[j++];
        System.arraycopy(t,0,a,l,k);
        return c;
    }
}
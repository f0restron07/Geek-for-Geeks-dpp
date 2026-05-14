class Solution{
    public ArrayList<Integer> search(int[] a,int[] b){
        int n=a.length,m=b.length;
        ArrayList<Integer> r=new ArrayList<>();
        int[] l=new int[m];
        for(int i=1,k=0;i<m;i++){
            while(k>0&&b[k]!=b[i]){
                k=l[k-1];
            }
            if(b[k]==b[i]){
                k++;
            }
            l[i]=k;
        }
        for(int i=0,k=0;i<n;i++){
            while(k>0&&b[k]!=a[i]){
                k=l[k-1];
            }
            if(b[k]==a[i]){
                k++;
            }
            if(k==m){
                r.add(i-m+1);
                k=l[k-1];
            }
        }
        return r;
    }
}